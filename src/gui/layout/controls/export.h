#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( CONTROLS_LIBRARY )
    #  define CONTROLS_EXPORT   __declspec(dllexport)
    #else
    #  define CONTROLS_EXPORT   __declspec(dllimport)
    #endif
#else
    #define CONTROLS_EXPORT
#endif
