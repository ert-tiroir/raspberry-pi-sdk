
#ifdef VIRTUAL
#include <rpi/virtual/iostream.h>
#else
#include <rpi/local/iostream.h>
#endif

#define info(...) { printf("[INFO] "); printf(__VA_ARGS__); }
#define debug(...) { printf("[DEBUG] "); printf(__VA_ARGS__); }
#define warning(...) { printf("[WARNING] "); printf(__VA_ARGS__); }
#define danger(...) { printf("[DANGER] "); printf(__VA_ARGS__); }
