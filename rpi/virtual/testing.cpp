
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
