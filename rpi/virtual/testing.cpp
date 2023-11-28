
#include <rpi/testing.h>
#include <rpi/iostream.h>

#include <algorithm>

std::string padTo (std::string str, int size) {
    while (str.size() < size)
        str += " ";
    return str;
}

void TestRunner::register_test (TestCase* test) {
    test_cases.push_back( test );
}

void TestRunner::run_all () {
    use_auto_flush();
    printf("Running test cases...\n\n");

    std::sort( test_cases.begin(), test_cases.end(), [](TestCase* a, TestCase* b) {
        return a->getTestMetadata() < b->getTestMetadata();
    } );

    int maxNameSize = 0;
    for (TestCase* testCase : test_cases) {
        TestCase_Information testInfo = testCase->getTestMetadata();
    
        maxNameSize = std::max( maxNameSize, (int) testInfo.name.size() );
    }

    std::string lastGroup = "";
    for (TestCase* testCase : test_cases) {
        TestCase_Information testInfo = testCase->getTestMetadata();
        if (lastGroup != testInfo.group) {
            printf("Running test group '%s'...\n", testInfo.group.c_str());
            lastGroup = testInfo.group;
        }

        std::string name = padTo("'" + testInfo.name + "'...", maxNameSize + 7);

        printf("    Running test %s", name.c_str());
        testCase->setup();

        bool result = testCase->run();

        if (result) {
            printf("\033[1;32mOK\n");
        } else { printf("\033[1;31mWRONG ANSWER\033[0m"); }

        printf("\n");
    }
}

void run_all (construct_runner func) {
    TestRunner* runner = func();

    runner->run_all();

    delete runner;
}
