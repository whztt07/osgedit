#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( LAY_LIBRARY )
    #  define LAY_EXPORT   __declspec(dllexport)
    #else
    #  define LAY_EXPORT   __declspec(dllimport)
    #endif
#else
    #define LAY_EXPORT
#endif
