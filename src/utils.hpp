#pragma once

#include <string>
#include <functional>

void log(const std::string& msg);
void error(const std::string& msg);
void info(const std::string& msg);

void count_fps(double update_interval, const std::function<void(const std::string&)>& output);