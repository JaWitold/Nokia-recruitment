#include <iostream>
#include <string>

using namespace std;

int solution(string& S) {
	int count = 0;
	unsigned int firstOne = S.find("1");
	if (firstOne == string::npos) return 0;
	S = S.substr(firstOne);
	if (S.empty()) return 0;

	do {
		
		//is even or not
		bool even = S.back() == '0';
		
		if (even) {
			S.pop_back();
		} else {
			S[S.length() - 1] = '0';
		}

		count++;

	} while (S != "0");

	return count;
}


int main(int argc, char** argv) {

	string s = "011100";
	std::cout << solution(s) << std::endl;

	return 0;
}