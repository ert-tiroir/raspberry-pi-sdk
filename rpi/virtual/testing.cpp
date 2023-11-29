
/**********************************************************************************/
/* rpi/virtual/testing.cpp                                                        */
/*                                                                                */
/* This file implements the behavior for testing in the virtual context.          */
/**********************************************************************************/
/*                   This file is part of the Raspberry Pi SDK                    */
/*                     github.com/ert-tiroir/raspberry-pi-sdk                     */
/**********************************************************************************/
/* Copyright (c) 2023 ert-tiroir                                                  */
/*                                                                                */
/* Permission is hereby granted, free of charge, to any person obtaining a copy   */
/* of this software and associated documentation files (the "Software"), to deal  */
/* in the Software without restriction, including without limitation the rights   */
/* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      */
/* copies of the Software, and to permit persons to whom the Software is          */
/* furnished to do so, subject to the following conditions:                       */
/*                                                                                */
/* The above copyright notice and this permission notice shall be included in all */
/* copies or substantial portions of the Software.                                */
/*                                                                                */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    */
/* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         */
/* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  */
/* SOFTWARE.                                                                      */
/**********************************************************************************/

#include <rpi/stdlib.h>

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
    bool auto_flush_state = auto_flush();

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

    std::vector<bool>        results (test_cases.size());
    std::vector<std::string> stdouts (test_cases.size());
    int index = 0;

    int total = 0;
    int valid = 0;
    int error = 0;

    for (TestCase* testCase : test_cases) {
        TestCase_Information testInfo = testCase->getTestMetadata();
        if (lastGroup != testInfo.group) {
            printf("Running test group '%s'...\n", testInfo.group.c_str());
            lastGroup = testInfo.group;
        }

        std::string name = padTo("'" + testInfo.name + "'...", maxNameSize + 7);

        printf("    Running test %s", name.c_str());

        reset_stdlib();
        testCase->setup();

        bool result = testCase->run();

        results[index] = result;
        stdouts[index] = get_buffer();
        index ++;

        total ++;
        if (result) valid ++;
        else        error ++;

        clear_buffer  ();
        use_auto_flush();

        if (result) {
            printf("\033[1;32mOK\033[0m");
        } else { printf("\033[1;31mWRONG ANSWER\033[0m"); }

        printf("\n");
    }

    use_auto_flush();

    printf("\n");

    index = - 1;
    for (TestCase* testCase : test_cases) {
        index ++;
        if (results[index]) continue ;

        TestCase_Information testInfo = testCase->getTestMetadata();
    
        printf("========= STDOUT for test case %s::%s =========\n", testInfo.group.c_str(), testInfo.name.c_str());
        printf("%s", stdouts[index].c_str());
        if (stdouts[index].size() == 0 || stdouts[index][stdouts[index].size() - 1] != '\n')
            printf("\n");
    } 

    printf("DIAGNOSTICS FOR THE TESTED PROJECT\n\n");
    printf("         TEST CASES COUNT : %d\n\n", total);
    printf("         VALID TEST CASES : %d\n", valid);
    printf("         WRONG TEST CASES : %d\n\n", error);

    if (valid == total && error == 0) {
        printf("The software is production ready.\n\n");
        exit(0);
    } else {
        printf("THERE IS AN ERROR, THE SOFTWARE IS NOT PRODUCTION READY.\n\n");
        exit(1);
    }

    stop_auto_flush();
    if (auto_flush_state)
        use_auto_flush();
}

void run_all (construct_runner func) {
    TestRunner* runner = func();

    runner->run_all();

    delete runner;
}
