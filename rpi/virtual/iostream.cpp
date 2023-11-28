
#include <rpi/iostream.h>

bool              is_auto_flushing = false;
std::string       buffer           = "";

void append_buffer (std::string data) {
    buffer += data;

    if (is_auto_flushing) flush_buffer();
}
std::string get_buffer () {
    return buffer;
}
void clear_buffer () {
    buffer = "";
}
void flush_buffer () {
    std::cout << buffer;
    clear_buffer();
}

bool      auto_flush () { return is_auto_flushing;  }
void  use_auto_flush () { is_auto_flushing = true;  }
void stop_auto_flush () { is_auto_flushing = false; }
