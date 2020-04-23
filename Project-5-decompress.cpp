#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <iterator>
#include <algorithm>  // for sort function
using namespace std;

// Utility comparator function to pass to the sort() module
// Ref: https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp
bool sortByVal(const pair<string, int>& a, const pair<string, int>& b) {
	return (a.second > b.second);
}

int main(int argc, char* argv[]) {

	string fileName = argv[1];
	ifstream myInputFile;
	string token;
	char aChar;
	myInputFile.open(fileName);
	
	// Create a string array to store the word
	string tokenArr[150];
	int i = 0;

	// Split the first line into a string array
	string line1;
	getline(myInputFile, line1);
	string word = "";
	for (auto x : line1) {
		if (x == ' ') {
			//cout << word << endl;
			tokenArr[i] = word;
			i++;
			word = "";
		}
		else {
			word = word + x;
		}
	}
	//cout << word << endl;

	string line2;
	getline(myInputFile, line2);
	for (auto x : line2) {
		if (x == ' ') {
			int idx = stoi(word);
			cout << tokenArr[idx - 1] << " ";
			word = "";
		}
		else {
			word = word + x;
		}
	}
	//cout << word << endl;

	// Close the file
	myInputFile.close();
	return 0;
}