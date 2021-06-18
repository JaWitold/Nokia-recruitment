#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<int>& A) {

	sort(A.begin(), A.end());
	
	if (A.size() == 0) {
		return 0;
	}
	else if (A.size() == 1) {
		return A[0];
	}
	else if (A.size() == 2) {
		return A[0] + A[1];
	}
	else {


		for (int i = 0; i < A.size() - 1; i++) 
			A[i + 1] += A[i];

		return A.back() + A[A.size() - 2];
	}
}


int main(int argc, char** argv) {

	vector<int> a = {100, 250, 1000 };
	cout << solution(a) << endl;

	return 0;
}