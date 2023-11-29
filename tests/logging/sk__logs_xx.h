
#include <rpi/testing.h>

#include <tests/logging/sk__logs_01.h>

void add_sk_logs (TestRunner* runner) {
    runner->register_test( new SK__LOGS_01() );
}
