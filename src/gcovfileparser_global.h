#ifndef GCOVFILEPARSER_GLOBAL_H
#define GCOVFILEPARSER_GLOBAL_H

//#if defined(GCOVFILEPARSER_LIBRARY)
//#  define GCOVFILEPARSERSHARED_EXPORT Q_DECL_EXPORT
//#else
//#  define GCOVFILEPARSERSHARED_EXPORT Q_DECL_IMPORT
//#endif

#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
    //  Microsoft
    #if defined(GCOVFILEPARSER_LIBRARY)
        #define GCOVFILEPARSERSHARED_EXPORT __declspec(dllexport)
    #else
        #define GCOVFILEPARSERSHARED_EXPORT __declspec(dllimport)
    #endif
#elif defined(__linux__) || defined(UNIX) || defined(__unix__) || defined(LINUX)
    //  GCC
    #if defined(GCOVFILEPARSER_LIBRARY)
        #define GCOVFILEPARSERSHARED_EXPORT __attribute__((visibility("default")))
    #else
        #define GCOVFILEPARSERSHARED_EXPORT
    #endif
#else
//  do nothing and hope for the best?
    #define GCOVFILEPARSERSHARED_EXPORT
    #pragma WARNING: Unknown dynamic link import/export semantics.
#endif

#endif // GCOVFILEPARSER_GLOBAL_H
