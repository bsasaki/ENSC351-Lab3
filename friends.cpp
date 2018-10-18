#include "friends.h"

using namespace std;

constexpr int f_MAX_THREADS = 4;
mutex fmtx;
std::vector<std::thread> f_threads;
std::vector<f_pair> fmaps;

int main() {
	//single_thread();
	ifstream in_file;
	in_file.open("f_in.txt", std::ifstream::in);
	std::vector<std::string> lines = f_input_read(in_file);

	for (int i = 0; i < f_MAX_THREADS; i++) {
		f_threads.push_back(std::thread(f_map_thread, lines, i));
	}

	for (int i = 0; i < f_MAX_THREADS; i++) {
		f_threads[i].join();
	}

	f_threads.clear();

	bubblesort(fmaps);

	std::vector<std::vector<f_pair>> groups_of_keys = pre_reduce(fmaps);

	cin.get();
	return 0;
}

void single_thread() {
	ifstream in_file;
	in_file.open("f_in.txt", std::ifstream::in);
	std::vector<std::string> lines = f_input_read(in_file);
	for (int i = 0; i < lines.size(); i++) {
		std::string this_line = lines[i];
		std::string p1;
		p1 = this_line[0];
		for (int j = i; j < lines.size(); j++) {
			if (this_line[j])
			std::string p2;
			//p2 = lines[i][j];
			//this is unfinished
		}
	}
}

std::vector<std::string> f_input_read(std::ifstream& in_file) {
	/* input_read- Section 4.1.1
	   Purpose: return vector where each memeber is a word
	   Input: text file to perform word count on
	   Output: vector with each word separated
	   Note: does not check for delimeters, only spaces.
			 We can fix that later if we need to
	*/
	std::vector<std::string> vect;
	string word;
	while (std::getline(in_file, word)) {
		vect.push_back(word);
	}
	return vect;
}

void f_map_thread(std::vector<std::string> lines, int tid) {
	std::vector<f_pair> p;
	for (int i = tid; i < lines.size(); i += 4) {
		fmtx.lock();
		p = f_create_pair(lines[i]);
		fmaps.insert(fmaps.end(), p.begin(), p.end());
		fmtx.unlock();
	}
}

std::vector<f_pair> f_create_pair(std::string line) {
	/* create_pair- Section 4.1.2
	   Formerly called "map_func"
	   Purpose: creates a key-value pair with a value one for a given key
	   Input: string which will be the key of the key-value pair
	   Output: key-value pair
	*/
	std::vector<f_pair> pairs;
	std::string friends;
	std::string me;
	me = line[0];
	for (int i = 1; i < line.length(); i++) {
		if (!isalpha(line[i]))
			continue;
		else {
			friends += line[i];
		}
	}
	for (int i = 0; i < friends.length(); i++) {
		f_pair p;
		if (me < string(1, friends[i])) {
			p.key = me + friends[i];
		}
		else {
			p.key = friends[i] + me;
		}
		p.value = friends;
		pairs.push_back(p);
	}
	return pairs;
}

void bubblesort(std::vector<f_pair> &strings) {
	typedef std::vector<myMap>::size_type size_type;
	for (size_type i = 1; i < strings.size(); ++i) // for n-1 passes
	{
		// In pass i,compare the first n-i elements
		// with their next elements
		for (size_type j = 0; j < (strings.size() - 1); ++j)
		{
			if (strings[j].key > strings[j + 1].key)
			{
				f_pair temp = strings[j];
				strings[j].key = strings[j + 1].key;
				strings[j + 1] = temp;
			}
		}
	}
}

std::vector<std::vector<f_pair>> pre_reduce(std::vector<f_pair> single_words) {
	/* pre-reduce
	   this function takes the bubble-sorted pairs and groups together the pairs with the same keys, so they can go into reduce
	Input: Vector of maps, already sorted alphabetically
	Output: Vector of vectors of maps, each vector holding all the pairs with the same key
	*/
	std::vector<std::vector<f_pair>> master;
	std::vector<f_pair> dummy;
	for (int i = 0; i < single_words.size(); i += 2) {
		dummy.push_back(single_words[i]);
		dummy.push_back(single_words[i + 1]);
		master.push_back(dummy);
		dummy.clear();
	}
	return master;
}