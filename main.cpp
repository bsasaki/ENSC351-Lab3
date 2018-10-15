/*ENSC 351 Lab 3
Authors: Bennett Sasaki & Jordan Kam

*/
#include "Header.h"

using namespace std;

int main() {
	ifstream in_file;
	std::map<std::string, int> wordCount;
	in_file.open("L3In.txt", std::ifstream::in);
	//wordCount = first_word_counter(in_file);

	std::vector<std::string> words; //Vector to hold unsorted words
	words = input_read(in_file);

	cin.get();

	in_file.close();
	return 0;
}

std::map<std::string, int> first_word_counter(ifstream& in_file) {
/* word_counter- Section 3
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

std::vector<std::string> input_read(std::ifstream& in_file) {
/* input_read- Section 4.1.1
   Purpose: return vector where each memeber is a word
   Input: text file to perform word count on
   Output: vector with each word separated
   Note: does not check for delimeters, only spaces.
		 We can fix that later if we need to
*/
	std::vector<std::string> vect;
	char* word = new char;
	while (in_file >> word) {
		vect.push_back(word);
	}
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << endl;
	}
	return vect;
}

std::map<std::string, int> map_func(std::vector<std::string>) {

}