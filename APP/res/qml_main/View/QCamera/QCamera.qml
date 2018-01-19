import QtQuick 2.0
import QtQuick.Controls 2.1
import QtMultimedia 5.8

import com.view.ccamera 1.0
import "../../../qml_com"

Rectangle {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    color:ui.backColor

    property bool _decodeingLock:false

    StackView.onStatusChanged: {
        if(StackView.status==StackView.Active){
            rootItem.refresh()
            startCamera()
        }
        if(StackView.status==StackView.Deactivating){
            stopCamera()
        }
    }

    Keys.enabled: true

    Keys.onReleased: {
        if(event.key===Qt.Key_Back){
            event.accepted = true
            subBack()
        }
    }

    function refresh(){
        rootItem.forceActiveFocus()
        if(camera.availability!==Camera.Available){
            sysBus.showSysNote("相机不可用，请稍后重试")
            subBack()
        }
        else{
            camera.imageProcessing.setWhiteBalanceMode(CameraImageProcessing.WhiteBalanceAuto)
        }
    }

    function subBack(){
        cViewManager.popQml()
    }

    function cameraFocusing(){
        if (camera.lockStatus!==Camera.Unlocked){
            camera.unlock()
        }
        _decodeingLock=true;
        camera.searchAndLock()
    }

    function getImageSnap(){
        var code=cCamera.decoder(output)
        if(code!==""){
            stopCamera()
            textResult.text=code
            return
        }
        cameraFocusing()
    }

    function stopCamera(){
        btnStop.enabled=false
        camera.stop()
        btnStart.enabled=true
    }
    function startCamera(){
        textResult.text=""
        btnStart.enabled=false
        camera.start()
        btnStop.enabled=true
        cameraFocusing()
    }

    Camera{
        id: camera
        captureMode:Camera.CaptureViewfinder
//        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceAuto
        focus
        {
            focusMode: CameraFocus.FocusAuto
            focusPointMode: CameraFocus.FocusPointAuto
        }
        exposure
        {
//            exposureCompensation: -1.0
            exposureMode: Camera.ExposureAuto
        }
        onLockStatusChanged: {
            if(_decodeingLock){
                if(camera.lockStatus===Camera.Locked){
                    _decodeingLock=false
                    getImageSnap()
                }
            }
        }

        onError: {
            switch(errorCode){
            case Camera.NoError:
                break;
            case Camera.CameraError:
                console.warn("CameraError")
                console.warn(errorString)
                sysBus.showSysNote(errorString)
                subBack()
                break;
            case Camera.InvalidRequestError:
                console.warn("InvalidRequestError")
                console.warn(errorString)
                sysBus.showSysNote(errorString)
                subBack()
                break;
            case Camera.ServiceMissingError:
                console.warn("ServiceMissingError")
                console.warn(errorString)
                sysBus.showSysNote(errorString)
                subBack()
                break;
            case Camera.NotSupportedFeatureError:
                console.warn("NotSupportedFeatureError")
                console.warn(errorString)
                sysBus.showSysNote(errorString)
                subBack()
                break;
            default:
                console.debug("UnKnown Error")
                console.warn(errorString)
                sysBus.showSysNote(errorString)
                subBack()
                break;
            }
        }
    }

    VideoOutput{
        id: output
        width:Math.min(parent.width,parent.height)*0.8
        height: width
        anchors.centerIn: parent
        source: camera
        focus : true
        autoOrientation: true
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: VideoOutput.PreserveAspectCrop
    }

    Text{
        id:textResult
        anchors.centerIn: parent
        width: parent.width*0.8
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        verticalAlignment:Text.AlignVCenter
    }

    Column{
        anchors.top: parent.top
        anchors.topMargin: global.em
        anchors.right: parent.right
        anchors.rightMargin: global.em
        spacing: global.em * 0.5

        Button{
            id:btnStart
            text:"Start"
            enabled: false
            onClicked: {
                startCamera()
            }
        }

        Button{
            id:btnStop
            text:"Stop"
            onClicked: {
                stopCamera()
            }
        }

        Button{
            id:btnBack
            text: "Back"
            onClicked: {
                subBack()
            }
        }
    }

    CCamera{
        id:cCamera
    }
}
