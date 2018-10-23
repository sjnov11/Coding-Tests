#include <iostream>
#include <string>
#include <map>
using namespace std;

void go(string str1, string str2) {
	//if (str1 == "" && str2 == "") cout << 1 * 65536 << endl;
	map<string, int> m1;
	for (int i = 0; i + 1 < str1.size(); i++) {
		if ( !((str1[i] >= 'A' && str1[i] <='Z') || (str1[i]>='a' && str1[i] <='z') )) continue;
		if (!((str1[i+1] >= 'A' && str1[i+1] <= 'Z') || (str1[i+1] >= 'a' && str1[i+1] <= 'z'))) continue;
		if (str1[i] > 'Z') {
			str1[i] = str1[i] - 'a' + 'A';
		}
		if (str1[i+1] > 'Z') {
			str1[i+1] = str1[i+1] - 'a' + 'A';
		}
		string elem = str1.substr(i, 2);
		if (m1.find(elem) != m1.end()) {
			m1[elem]++;
		}
		else {
			m1.insert({ elem,1 });
		}
	}
	map<string, int> m2;
	for (int i = 0; i + 1 < str2.size(); i++) {
		if (!((str2[i] >= 'A' && str2[i] <= 'Z') || (str2[i] >= 'a' && str2[i] <= 'z'))) continue;
		if (!((str2[i+1] >= 'A' && str2[i+1] <= 'Z') || (str2[i+1] >= 'a' && str2[i+1] <= 'z'))) continue;
		if (str2[i] > 'Z') {
			str2[i] = str2[i] - 'a' + 'A';
		}
		if (str2[i + 1] > 'Z') {
			str2[i + 1] = str2[i + 1] - 'a' + 'A';
		}
		string elem = str2.substr(i, 2);
		if (m2.find(elem) != m2.end()) {
			m2[elem]++;
		}
		else {
			m2.insert({ elem,1 });
		}
	}
	
	
	map<string, int> answer1;
	map<string, int> answer2;
	for (auto elem1 : m1) {
		string elem1_s = elem1.first;
		int elem1_c = elem1.second;

		auto elem2 = m2.find(elem1_s);
		if (elem2 == m2.end()) {
			answer1.insert({ elem1_s, 0 });
			answer2.insert({ elem1_s, elem1_c });
		}
		else {
			int elem2_c = elem2->second;
			if (elem1_c >= elem2_c) {
				answer1.insert({ elem1_s, elem2_c });
				answer2.insert({ elem1_s, elem1_c });
			}
			else {
				answer1.insert({ elem1_s, elem1_c });
				answer2.insert({ elem1_s, elem2_c });
			}
		}
	}

	for (auto elem2 : m2) {
		string elem2_s = elem2.first;
		int elem2_c = elem2.second;

		if (answer1.find(elem2_s) == answer1.end()) {
			answer1.insert({ elem2_s, 0 });
			answer2.insert({ elem2_s, elem2_c });
		}
	}

	int gyo = 0;
	int hap = 0;

	for (auto p : answer1) {
		gyo += p.second;
	}
	for (auto p : answer2) {
		hap += p.second;
	}
	if (hap == 0) {
		cout << 1 * 65536 << endl;
	}
	else 
		cout << int(((double)gyo / (double)hap) * 65536) << endl;
}

int main() {
	string s1, s2;
	s1 = "FRANCE";
	s2 = "french";
	go(s1, s2);

	s1 = "handshake";
	s2 = "shake hands";
	go(s1, s2);

	s1 = "aa1+aa2";
	s2 = "AAAA12";
	go(s1, s2);

	s1 = "E=M*C^2";
	s2 = "e=m*c^2";
	go(s1, s2);

}