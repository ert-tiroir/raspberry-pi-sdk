#pragma once
#include <iostream>
#include <string>

const auto __printf = printf;

void             flush_buffer  ();
void             clear_buffer  ();
std::string      get_buffer    ();
void             append_buffer (std::string data);

#define SNPRINTF_BUFFER_SIZE 500
#define printf(...) { char snprintf_buffer[SNPRINTF_BUFFER_SIZE]; std::snprintf( snprintf_buffer, SNPRINTF_BUFFER_SIZE, __VA_ARGS__ ); append_buffer(snprintf_buffer); }
