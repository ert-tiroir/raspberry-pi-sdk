#pragma once
#include <iostream>
#include <string>

void             flush_buffer  ()                 {};
void             clear_buffer  ()                 {};
std::string      get_buffer    ()                 { return ""; };
void             append_buffer (std::string data) {};
