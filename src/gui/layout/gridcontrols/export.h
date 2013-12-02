#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( GRID_CONTROLS_LIBRARY )
    #  define GRID_CONTROLS_EXPORT   __declspec(dllexport)
    #else
    #  define GRID_CONTROLS_EXPORT   __declspec(dllimport)
    #endif
#else
    #define GRID_CONTROLS_EXPORT
#endif
