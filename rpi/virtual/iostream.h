
/**********************************************************************************/
/* rpi/virtual/iostream.h                                                         */
/*                                                                                */
/* This file is an extension of the default rpi/iostream.h file, designed to      */
/* intercept standard output from printf to the custom standard output buffer to  */
/* allow for the standard output to be tested                                     */
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

#pragma once

const auto __printf = printf;

#define SNPRINTF_BUFFER_SIZE 500
#define printf(...) { char snprintf_buffer[SNPRINTF_BUFFER_SIZE]; std::snprintf( snprintf_buffer, SNPRINTF_BUFFER_SIZE, __VA_ARGS__ ); append_buffer(snprintf_buffer); }
