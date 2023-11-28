
#include <rpi/iostream.h>

void          append_buffer (std::string data) { }
std::string   get_buffer    ()                 { return ""; }
void          clear_buffer  ()                 { }
void          flush_buffer  ()                 { }

bool      auto_flush () { return true; }
void  use_auto_flush () { }
void stop_auto_flush () { }