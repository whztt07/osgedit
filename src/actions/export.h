#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( ACTION_LIBRARY )
    #  define ACTION_EXPORT   __declspec(dllexport)
    #else
    #  define ACTION_EXPORT   __declspec(dllimport)
    #endif
#else
    #define ACTION_EXPORT
#endif
