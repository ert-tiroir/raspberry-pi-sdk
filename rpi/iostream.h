
/**********************************************************************************/
/* rpi/iostream.h                                                                 */
/*                                                                                */
/* This file declares the default behavior of the custom input / output systems   */
/* for the Raspberry Pi SDK                                                       */
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

#include <iostream>
#include <string>

void             flush_buffer  ();
void             clear_buffer  ();
std::string      get_buffer    ();
void             append_buffer (std::string data);

bool      auto_flush ();
void  use_auto_flush ();
void stop_auto_flush ();

#ifdef VIRTUAL
#include <rpi/virtual/iostream.h>
#endif

#define info(...) { printf("[INFO] "); printf(__VA_ARGS__); }
#define debug(...) { printf("[DEBUG] "); printf(__VA_ARGS__); }
#define warning(...) { printf("[WARNING] "); printf(__VA_ARGS__); }
#define danger(...) { printf("[DANGER] "); printf(__VA_ARGS__); }
