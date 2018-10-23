#include <iostream>
#include <string>
#include <vector>
using namespace std;
string input;
vector<string> answer;
bool invalid = false;
bool one = false;
bool two = false;
bool isLower(char c) {
	if (c > 'Z')
		return true;
	else
		return false;
}

bool hasLower(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (isLower(s[i]))
			return true;
	}
	return false;
}

string stripWord(string s, int c) {
	string ret;
	if (c == 1) {
		for (int i = 0; i < s.size(); i+=2) {
			ret += s[i];
		}
	}
	else if (c == 2) {
		ret = s.substr(1, s.size() - 2);
	}
	return ret;
}

string parseString(string s) {
	
	int start;
	for (start = 0; start < s.size(); start++) {
		if (isLower(s[start])) break;
	}
	int cnt = 1;
	int last = start;
	for (int i = start + 1; i < s.size(); i++) {
		if (s[i] == s[start]) {
			cnt++;
			last = i;
		}
	}
			
	
	if (cnt == 1 || cnt >= 3) {
		if (one) {
			invalid = true;
			return "";
		}
		one = true;
		if (start - 1 < 0) {
			invalid = true;
			return "";
		}
		
		string head = s.substr(0, start - 1);
		string word = s.substr(start - 1, last - start + 3);
		if (last - start + 3 > word.size()) {
			invalid = true;
			return "";
		}
		s.replace(s.find(word), word.size(), "");

		if (head != "") {
			answer.push_back(head);
			s.replace(s.find(head), head.size(), "");
		}
		word = stripWord(word, 1);
		if (hasLower(word)) {
			parseString(word);
		}
		else {
			answer.push_back(word);
		}
		
		
	}
	else {
		if (start + 2 == last) {
			if (start == 0 || last == s.size()-1) {
				if (two) {
					invalid = true;
					return "";
				}
				
				string head = s.substr(0, start);
				string word = s.substr(start, last - start + 1);
				
				if (two && head !="") {
					invalid = true;
				}

				s.replace(s.find(word), word.size(), "");

				if (head != "") {
					answer.push_back(head);
					s.replace(s.find(head), head.size(), "");
				}
				word = stripWord(word, 2);
				if (hasLower(word)) {
					parseString(word);
				}
				else {
					answer.push_back(word);
				}
				
			}
			
			else {
				if (one) {
					invalid = true;
					return "";
				}
				string head = s.substr(0, start-1);
				string word = s.substr(start - 1, last - start + 3);
				if (last - start + 3 > word.size()) {
					invalid = true;
					return "";
				}
				s.replace(s.find(word), word.size(), "");

				if (head != "") {
					answer.push_back(head);
					s.replace(s.find(head), head.size(), "");
				}
				
				word = stripWord(word, 1);
				if (hasLower(word)) {
					parseString(word);
				}
				else {
					answer.push_back(word);
				}
				
			}
		}
		else if (start + 1 == last) {
			invalid = true;
			return "";
		}
		else {
			if (two) {
				invalid = true;
				return "";
			}
			string head = s.substr(0, start);
			string word = s.substr(start, last - start + 1);
			
			s.replace(s.find(word), word.size(), "");
			
			if (head != "") {
				answer.push_back(head);
				s.replace(s.find(head), head.size(), "");
			}
			word = stripWord(word, 2);
			if (hasLower(word)) {
				word = parseString(word);
			}
			else {
				answer.push_back(word);
			}
			
		}
	}
	return s;
}



int main() {
	cin >> input;

	while (hasLower(input)) {
		one = false;
		two = false;
		input = parseString(input);
	}
	if (invalid) {
		cout << "invalid" << '\n';
		return 0;
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	if (input != "") {
		cout << input;
	}
	cout << '\n';
	return 0;
}