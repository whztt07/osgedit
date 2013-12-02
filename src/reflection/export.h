#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
    #if defined( REFLECTION_LIBRARY )
    #  define REFLECTION_EXPORT   __declspec(dllexport)
    #else
    #  define REFLECTION_EXPORT   __declspec(dllimport)
    #endif
#else
    #define REFLECTION_EXPORT
#endif
