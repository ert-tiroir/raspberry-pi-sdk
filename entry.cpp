
#include <rpi/iostream.h>

int main () {
    debug("HELP %d\n", 5);
    danger("DIED %c\n", 'c');
    flush_buffer();
    flush_buffer();
}
