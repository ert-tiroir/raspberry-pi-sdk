
#include <rpi/iostream.h>
#include <thread>

int main () {
    use_auto_flush();
    debug("HELP %d\n", 5);
    std::this_thread::sleep_for( std::chrono::milliseconds(3000) );
    danger("DIED %c\n", 'c');
    flush_buffer();
    flush_buffer();
}
