
/**********************************************************************************/
/* rpi/virtual/iostream.cpp                                                       */
/*                                                                                */
/* This file contains the implementation of the custom standard output            */
/* intercepter to allow for testing on stdout.                                    */
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

#include <rpi/iostream.h>

bool              is_auto_flushing = false;
std::string       buffer           = "";

void append_buffer (std::string data) {
    buffer += data;

    if (is_auto_flushing) flush_buffer();
}
std::string get_buffer () {
    return buffer;
}
void clear_buffer () {
    buffer = "";
}
void flush_buffer () {
    std::cout << buffer;
    clear_buffer();
}

bool      auto_flush () { return is_auto_flushing;  }
void  use_auto_flush () { is_auto_flushing = true;  }
void stop_auto_flush () { is_auto_flushing = false; }
