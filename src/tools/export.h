#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( TOOLS_LIBRARY )
    #  define TOOLS_EXPORT   __declspec(dllexport)
    #else
    #  define TOOLS_EXPORT   __declspec(dllimport)
    #endif
#else
    #define TOOLS_EXPORT
#endif
