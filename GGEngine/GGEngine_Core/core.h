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


#if defined(GGE_BUILD_STATIC)
#  define GGE_API
#else
#if defined(GGE_BUILD_DLL)
#  define GGE_API Q_DECL_EXPORT
#else
#  define GGE_API Q_DECL_IMPORT
#endif
#endif

//#ifdef GGE_DEBUG
//#define GGE_ASSERT(x, ...) { if(!(x)) { GGE_ERROR("Assertion Failed: {0}", __VA_ARGS__); asm("int $3"); } }
//#define GGE_CORE_ASSERT(x, ...) { if(!(x)) { GGE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); asm("int $3"); } }
//#else
//#define GGE_ASSERT(x, ...)
//#define GGE_CORE_ASSERT(x, ...)

#define BIT(x) (1<<x)

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#endif // CORE_H
