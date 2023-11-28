
/**********************************************************************************/
/* rpi/local/iostream.cpp                                                         */
/*                                                                                */
/* This file contains the implementation of the intercepter in a non virtual      */
/* context, in that case, there is nothing to be done and everything is forwarded */
/* to the standard iostream library                                               */
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

void          append_buffer (std::string data) { }
std::string   get_buffer    ()                 { return ""; }
void          clear_buffer  ()                 { }
void          flush_buffer  ()                 { }

bool      auto_flush () { return true; }
void  use_auto_flush () { }
void stop_auto_flush () { }