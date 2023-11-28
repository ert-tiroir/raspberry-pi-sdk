
#include <rpi/testing.h>

struct TVCase : public TestCase {
    std::string a; std::string b;
    TVCase (std::string a, std::string b) : a(a), b(b) {}
    TestCase_Information getTestMetadata () {
        return { a, b };
    }
};

TestRunner* create_runner () {
    TestRunner* runner = new TestRunner();

    runner->register_test( new TVCase( "A", "A" ) );
    runner->register_test( new TVCase( "N", "H" ) );
    runner->register_test( new TVCase( "B", "G" ) );
    runner->register_test( new TVCase( "C", "G" ) );
    runner->register_test( new TVCase( "Nfhlerkfgtik", "E" ) );
    runner->register_test( new TVCase( "B", "F" ) );
    runner->register_test( new TVCase( "N", "B" ) );

    return runner;
}

int main () {
    run_all( create_runner );
}
