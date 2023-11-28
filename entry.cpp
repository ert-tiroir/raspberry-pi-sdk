
/**********************************************************************************/
/* entry.cpp                                                                      */
/*                                                                                */
/* This file is the entry point for the SDK when used in standalone to test the   */
/* virtual behavior of the SDK.                                                   */
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
