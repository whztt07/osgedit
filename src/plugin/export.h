#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( PLUGIN_LIBRARY )
    #  define PLUGIN_EXPORT   __declspec(dllexport)
    #else
    #  define PLUGIN_EXPORT   __declspec(dllimport)
    #endif
#else
    #define PLUGIN_EXPORT
#endif
