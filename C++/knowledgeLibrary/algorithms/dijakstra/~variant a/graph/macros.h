//  1 = Name of class members

#define DEBUGMODE 0
#if DEBUGMODE==1
#define printDebug(x) printf(x)
#define printEveryTime(x) printf(x)
#else
#define printDebug(x) //
#define printEveryTime(x) printf(x)
#endif