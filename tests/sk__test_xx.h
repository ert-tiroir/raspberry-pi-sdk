
#include <rpi/testing.h>

#include <tests/logging/sk__logs_xx.h>

TestRunner* create_runner () {
    TestRunner* runner = new TestRunner();

    add_sk_logs(runner);

    return runner;
}
