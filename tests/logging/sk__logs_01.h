
/**********************************************************************************/
/* tests/sk__logs_01.h                                                            */
/*                                                                                */
/* This file is responsible for the implementation of the SK__LOGS_01 test case,  */
/* testing the behavior of the virtual printf function                            */
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

struct SK__LOGS_01 : public TestCase {
private:
    std::string expected_buffer = "EASY PRINTF\nPRINTF INTEGERS 5, 6\nPRINTF CHARACTER c\n";
public:
    void setup () override {}
    bool run   () override {
        printf("EASY PRINTF\n");
        printf("PRINTF INTEGERS %d, %lld\n", 5, (long long) 6);
        printf("PRINTF CHARACTER %c\n", 'c');

        std::string result = get_buffer(); clear_buffer();

        if (result == expected_buffer) {
            printf("Error, virtual printf did not have the expected behavior\n\n");
            printf("/****************** result ******************/\n%s\n", result.c_str());
            printf("/***************** expected *****************/\n%s\n", expected_buffer.c_str());
            
            return false;
        }

        return true;
    }

    TestCase_Information getTestMetadata () override {
        return { "SK__LOGS_01", "SDK Logging" };
    }
};
