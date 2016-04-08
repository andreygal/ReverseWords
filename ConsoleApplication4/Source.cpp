#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream input_stream(argv[1]);
	if (!input_stream)
		cout << "Error: could not open " << argv[1] << endl; 
	ofstream output_stream(argv[2]);
	if (!output_stream)
		cout << "Error: could not open " << argv[2] << endl; 
	string word = "";
	string line = ""; 
	list<string> word_list; 
	int casenum{ 1 };
	getline(input_stream, word);
	while (getline(input_stream, line)) {
		istringstream is { line };
		while (is >> word) {
			word_list.emplace_front(word);
		}
		output_stream << "Case #" << casenum << ": "; 
		for (auto word : word_list)
			output_stream << word << " ";
		output_stream << endl;
		word_list.clear(); 
		casenum++; 
	}
	return 0; 
}