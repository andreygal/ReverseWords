#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

int main(int arc, char *argv[]) {
	ifstream input_stream(argv[1]);
	if (!input_stream)
		cout << "Error: could not open " << argv[1] << endl; 
	string word = "";
	string line = ""; 
	list<string> word_list; 
	int casenum{ 1 };
	
	while (getline(input_stream, line)) {
		istringstream is { line };
		while (is >> word) {
			word_list.emplace_front(word);
		}
		cout << "Case #" << casenum << ": "; 
		for (auto word : word_list)
			cout << word << " ";
		cout << endl;
		word_list.clear(); 
		casenum++; 
	}
	system("pause");
	return 0; 
}