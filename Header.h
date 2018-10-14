#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <map>

std::map<std::string, int> first_word_counter(std::ifstream& in_file);