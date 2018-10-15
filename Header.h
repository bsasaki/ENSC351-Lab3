#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <map>
#include <vector>
#include <string>
#include <list>

std::map<std::string, int> first_word_counter(std::ifstream& in_file);
std::vector<std::string> input_read(std::ifstream& in_file);
std::map<std::string, int> map_func(std::string key);
std::map<std::string, int> reduce(std::list<std::map<std::string, int>> l1);