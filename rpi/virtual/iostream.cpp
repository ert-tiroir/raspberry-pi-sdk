
#include <rpi/virtual/iostream.h>


std::string       buffer = "";

void append_buffer (std::string data) {
    buffer += data;
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
