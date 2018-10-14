/*ENSC 351 Lab 3
Authors: Bennett Sasaki & Jordan Kam

*/
#include "Header.h"

using namespace std;

const int MAX_WORD_COUNT = 10000;

int main() {
	ifstream in_file;
	std::map<std::string, int> wordCount;
	in_file.open("L3In.txt", std::ifstream::in);
	wordCount = first_word_counter(in_file);

	in_file.close();
	return 0;
}

std::map<std::string, int> first_word_counter(ifstream& in_file) {
/* word_counter
   Purpose: return word count
   Input: text file to perform word count on
   Output: total word count
   Note: does not check for delimeters, only spaces.
	   We can fix that later if we need to
*/
	std::map<std::string, int> wordMap;
	char* word = new char;

	while (in_file >> word) {
		wordMap[word]++;
	}

	return wordMap;
}