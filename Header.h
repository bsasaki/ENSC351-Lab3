#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <map>
#include <vector>
#include <string>

std::map<std::string, int> first_word_counter(std::ifstream& in_file);
std::vector<std::string> input_read(std::ifstream& in_file);
std::map<std::string, int> map_func(std::vector<std::string>);