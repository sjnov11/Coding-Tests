#include <iostream>
#include <string>
using namespace std;


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	int start_idx = S.find('1');
	int result = 1;
	for (int i = start_idx + 1; i < S.size(); i++) {
		if (S[i] == '0') result += 1;
		else if (S[i] == '1') result += 2;
	}
	return result;
}

int main() {
	string s = "0011100";
	cout << solution(s) << endl;
}