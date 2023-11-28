
#include <iostream>
#include <string>

void             flush_buffer  ();
void             clear_buffer  ();
std::string      get_buffer    ();
void             append_buffer (std::string data);

bool      auto_flush ();
void  use_auto_flush ();
void stop_auto_flush ();

#ifdef VIRTUAL
#include <rpi/virtual/iostream.h>
#endif

#define info(...) { printf("[INFO] "); printf(__VA_ARGS__); }
#define debug(...) { printf("[DEBUG] "); printf(__VA_ARGS__); }
#define warning(...) { printf("[WARNING] "); printf(__VA_ARGS__); }
#define danger(...) { printf("[DANGER] "); printf(__VA_ARGS__); }
