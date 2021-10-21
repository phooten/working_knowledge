// Definitions
// printDebug(x)        - only prints statements when debug mode is enabled
// printEverytime(x)    - prints statements regardless of debug mode

#define DEBUGMODE 0
#if DEBUGMODE==1
#define printDebug(x) printf(x)
#define printEveryTime(x) printf(x)
#else
#define printDebug(x) //
#define printEveryTime(x) printf(x)
#endif