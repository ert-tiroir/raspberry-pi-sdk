#pragma once

const auto __printf = printf;

#define SNPRINTF_BUFFER_SIZE 500
#define printf(...) { char snprintf_buffer[SNPRINTF_BUFFER_SIZE]; std::snprintf( snprintf_buffer, SNPRINTF_BUFFER_SIZE, __VA_ARGS__ ); append_buffer(snprintf_buffer); }
