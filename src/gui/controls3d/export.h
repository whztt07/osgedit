#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( CONTROLS3D_LIBRARY )
    #  define CONTROLS3D_EXPORT   __declspec(dllexport)
    #else
    #  define CONTROLS3D_EXPORT   __declspec(dllimport)
    #endif
#else
    #define CONTROLS3D_EXPORT
#endif
