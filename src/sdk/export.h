#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( SDK_LIBRARY )
    #  define SDK_EXPORT   __declspec(dllexport)
    #else
    #  define SDK_EXPORT   __declspec(dllimport)
    #endif
#else
    #define SDK_EXPORT
#endif
