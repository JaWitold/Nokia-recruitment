#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>


using namespace std;

int solution(string& S) {

	string SS = S;

	std::replace(SS.begin(), SS.end(), '?', '.');
	std::replace(SS.begin(), SS.end(), '!', '.');

	
	//lets divide by sentences
	vector<string> sentences = {};

	while (SS.length() > 0) {
		

		int firstDotIndex = SS.find(".");

		if (firstDotIndex == string::npos) {
			break;
		} else {
			sentences.push_back(SS.substr(0, firstDotIndex));
			SS = SS.substr(firstDotIndex + 1);
		}
	}

	int maxWords = 0;

	for (string& sentence : sentences) {

		if (sentence.length() == 0) break;

		char* str;
		str = &sentence[0];

		bool inSpaces = true;
		int numWords = 0;

		//checks all sentences char by char
		while (*str != '\0') {
			if (std::isspace(*str)) {
				inSpaces = true;
			}
			else if (inSpaces) {
				numWords++;
				inSpaces = false;
			}

			++str;
		}

		if (numWords > maxWords) {
			maxWords = numWords;
		}

	}

	return maxWords;
}

int main(int argc, char** argv) {

	string ss = "this is a debug message. this is second debug message and is print it? this is third debug message and You can read it if You want!";

	std::cout << solution(ss) << std::endl;

	std::getc;
	return 0;
}