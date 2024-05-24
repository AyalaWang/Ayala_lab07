// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int size = 0; 
	for (auto i = 0; i < 100; i++) { 
		for (size_t j = 0; j < table[i].size(); j++) { 
			size += table[i][j].second; 
		}
	}
	return size;
}

int WordCount::getNumUniqueWords() const {
	int size = 0;
	for (auto i = 0; i < 100; i++) { 
		size += table[i].size(); 
	}
	return size;
}

int WordCount::getWordCount(std::string word) const {
	word = makeValidWord(word);
	int a = hash(word)%100; 
	for (size_t i = 0; i < table[a].size(); i++) { 
		if (table[a][i].first == word) { 
			return table[a][i].second;
		}
	}
	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	word = makeValidWord(word);
	if (word == "") {
		return 0;
	}
	int a = hash(word)%100; 
	bool found = false;
	for (size_t i = 0; i < table[a].size(); i++) { 
		if (table[a][i].first == word) { 
			table[a][i].second++;
			found = true;
			return table[a][i].second;
		}
	}
	if (!found) {
		table[a].push_back(make_pair(word, 1));
		return 1;
	}
	return -1;
}

int WordCount::decrWordCount(std::string word) {
	word = makeValidWord(word);
	int a = hash(word)%100; 
	bool found = false;
	for (size_t i = 0; i < table[a].size(); i++) { 
		if (table[a][i].first == word) { 
			if (table[a][i].second == 1) { 
				table[a].erase(table[a].begin() + i);
				return 0;
			}
			table[a][i].second--;
			found = true;
			return table[a][i].second;
		}
	}
	if (!found) {
		return -1;
	}
	return -2;
}


bool WordCount::isWordChar(char c) {
	return (c >= 'A'&& c <= 'Z') || (c >= 'a'&& c <= 'z');
}

std::string WordCount::makeValidWord(std::string word) {
	string ret = "";
	for (char c : word) { 
		if (isWordChar(c)) {
			ret += tolower(c); 
		}
		else if (c == '-' || c == '\'') { 
			ret += c;
		}
	}
	while (ret[0] == '-' || ret[0] == '\'') { 
		ret.erase(ret.begin());
	}
	while (ret[ret.length()-1] == '-' || ret[ret.length()-1] == '\'') { 
		ret.erase(ret.length()-1);
	}
	return ret;
}

bool sortfunction1(pair<string, int> s1, pair<string, int> s2) { 
	return s1.first > s2.first; 
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	std::vector<std::pair<std::string, int> > listOfPairs; 
	for (vector<std::pair<std::string, int>> v : table) {
		for (std::pair<std::string, int> p : v) { 
			listOfPairs.push_back(p);
		}
	}

	std::sort(listOfPairs.begin(), listOfPairs.end(), sortfunction1); 
	for (std::pair<std::string, int> p : listOfPairs) { 
		out << p.first << "," << p.second << endl; 
	}
}

bool sortfunction2(pair<string, int> s1, pair<string, int> s2) { 
	return s1.second < s2.second; 
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	std::vector<std::pair<std::string, int> > listOfPairs; 
	for (vector<std::pair<std::string, int>> v : table) {
		for (std::pair<std::string, int> p : v) { 
			listOfPairs.push_back(p);
		}
	}

	std::sort(listOfPairs.begin(), listOfPairs.end(), sortfunction2); 
	for (std::pair<std::string, int> p : listOfPairs) { 
		out << p.first << "," << p.second << endl; 
	}
}

void WordCount::addAllWords(std::string text) {
	vector<string> words; 
	string currentString = "";
	for (char c : text) { 
		if (isWordChar(c)) {
            	currentString += c;
		}
		else if (c == ' ' || c == '\n' || c == '\t' || c == '\0') {	
            if (!currentString.empty()) {
				
                words.push_back(makeValidWord(currentString));
				incrWordCount(currentString);
                currentString = "";
            }
        } 
	}

	if (!currentString.empty()) {
        makeValidWord(currentString);
        words.push_back(currentString);
        incrWordCount(currentString);
    }
	/*for (string word : words) {
		cout << word << " ";
	}*/

	return;
}
