#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( CMD_LIBRARY )
    #  define CMD_EXPORT   __declspec(dllexport)
    #else
    #  define CMD_EXPORT   __declspec(dllimport)
    #endif
#else
    #define CMD_EXPORT
#endif
