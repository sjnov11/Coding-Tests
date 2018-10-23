#include <iostream>
#include <string>
using namespace std;

void go(string s) {
	string cur;
	int a = 0, b = 0, answer = 0;

	while (s.size()) {
		answer += a;
		a = b;
		cur = s.substr(0, 2);
		s = s.substr(2);
		char num = cur[0];
		char area = cur[1];
		if (area == '0') {
			b = 10;
			area = s[0];
			s= s.substr(1);
		}
		else 
			b = atoi(&num);
		if (area == 'D') {
			b = b * b;
		}
		else if (area == 'T') {
			b = b * b * b;
		}
		if (s.size() == 0) {
			continue;
		}
		else if (s[0] == '*') {
			a *= 2;
			b *= 2;
			s = s.substr(1);
		}
		else if (s[0] == '#') {
			b *= (-1);
			s = s.substr(1);
		}		
	}
	answer += a + b;
	cout << answer << endl;
}

int main() {
	string t;
	cin >> t;
	go(t);
}