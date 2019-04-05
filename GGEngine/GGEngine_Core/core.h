#ifndef CORE_H
#define CORE_H

#include <QtCore/qglobal.h>

#  ifdef Q_OS_WIN
#    define Q_DECL_EXPORT     __declspec(dllexport)
#    define Q_DECL_IMPORT     __declspec(dllimport)
#  elif defined(QT_VISIBILITY_AVAILABLE)
#    define Q_DECL_EXPORT     __attribute__((visibility("default")))
#    define Q_DECL_IMPORT     __attribute__((visibility("default")))
#  endif

#if defined(GGE_BUILD_DLL)
#  define GGE_API Q_DECL_EXPORT
#else
#  define GGE_API Q_DECL_IMPORT
#endif

#endif // CORE_H
