#ifndef LIBWIDGET_GLOBAL_H
#define LIBWIDGET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBWIDGET_LIBRARY)
#  define LIBWIDGETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBWIDGETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBWIDGET_GLOBAL_H
