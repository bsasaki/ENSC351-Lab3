#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>

struct myMap {
	std::string key;
	int value;
};

std::map<std::string, int> first_word_counter(std::ifstream& in_file);
std::vector<std::string> input_read(std::ifstream& in_file);
myMap map_func(std::string key);
myMap reduce(std::vector<myMap> v1);
void output(myMap m);
void bubblesort(std::vector<myMap> &strings);
