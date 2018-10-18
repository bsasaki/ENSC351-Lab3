#pragma once
#include "main_Header.h"

struct f_pair {
	std::string key;
	std::string value;
};

void single_thread();
std::vector<std::string> f_input_read(std::ifstream& in_file);
void f_map_thread(std::vector<std::string>, int tid);
std::vector<f_pair> f_create_pair(std::string line);
void bubblesort(std::vector<f_pair> &strings);
std::vector<std::vector<f_pair>> pre_reduce(std::vector<f_pair> single_words);