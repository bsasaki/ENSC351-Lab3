/*ENSC 351 Lab 3
Authors: Bennett Sasaki & Jordan Kam

*/
#include "ass3header.h"

using namespace std;
//MAX of 4 threads on this machine
const int maxthreads = 4;
int threads_created = 0;
std::thread mythread[maxthreads];
std::mutex mtx;
std::vector<myMap> maps;
myMap m;



int main() {
	ifstream in_file;
	//std::map<std::string, int> wordCount;
	in_file.open("L3In.txt", std::ifstream::in);
	//wordCount = first_word_counter(in_file);
	

	std::vector<std::string> words; //Vector to hold unsorted words
	words = input_read(in_file); //

	

	for (int i = 0; i <= words.size()-1; i++) {

		
		myMap m = map_func(words[i]); //implement multiple threads??
		maps.push_back(m);

	}

	bubblesort(maps);

	cout << "************************\n" << "Map vector sorted" << endl;
	for (int i = 0; i <= maps.size()-1; i++) {
		output(maps[i]);
	}
	cout << "******************\n";

	//TO DO...
	//need to group same "keys" together into vectors
	//need to input grouped vectors into map reduce
	//need to output result
	//Multithreading..
	//need threaded function of:
	/*for (int i = 0; i <= words.size()-1; i++) {

		
		myMap m = map_func(words[i]); 
		mtx.lock();
		maps.push_back(m);
		mtx.unlock();

	}*/
	//initialize threads in main func



	cin.get();

	in_file.close();
	return 0;
}

void bubblesort(std::vector<myMap> &strings)
{
	typedef std::vector<myMap>::size_type size_type;
	for (size_type i = 1; i < strings.size(); ++i) // for n-1 passes
	{
		// In pass i,compare the first n-i elements
		// with their next elements
		for (size_type j = 0; j < (strings.size() - 1); ++j)
		{
			if (strings[j].key > strings[j + 1].key)
			{
				myMap temp = strings[j];
				strings[j].key = strings[j + 1].key;
				strings[j + 1] = temp;
			}
		}
	}
}
/*void func(int n) {


	while (threads_created == 0) {
		//do nothing
	}

	mtx.lock();


	//exclusive code here
	mtx.unlock();



	//do threading processes here
	//cout << "Thread Number: " << n << "\n";
	//cout << "From thread ID: " << std::this_thread::get_id() << "\n";
}
*/


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

myMap map_func(std::string key) {
	/* map_func- Section 4.1.2
	   Purpose: creates a key-value pair with a value one for a given key
	   Input: string which will be the key of the key-value pair
	   Output: key-value pair
	   Note: does not check for delimeters, only spaces.
			 We can fix that later if we need to
	*/


	myMap m1;
	m1.key = key;
	m1.value = 1;
	return m1;
}

myMap reduce(std::vector<myMap> v1) {
	/* map_func- Section 4.1.3
	   Purpose: creates a single key-value pair given a list of pairs with the same keys
	   Input: list of key-value pairs, which should have the same key
	   Output: a single key-value pair with correct value
	   Note: does not check for delimeters, only spaces.
			 We can fix that later if we need to
	*/

	myMap m1;
	m1.key = v1[0].key;
	m1.value = v1.size();
	return m1;
}

void output(myMap m) {
	/* map_func- Section 4.1.4
   Purpose: outputs word count for a given key-value pair
   Input: a single key-value pair
   Output: N/A
*/
	cout <<"output " << m.key << ": " << m.value << "\n";
	return;
}