#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int n;
int Answer = 40320;
string all_friends = "ACFJMNRT";
string cond[100];

bool checkCondition(string line) {
	for (int i = 0; i < n; i++) {
		int a_idx = line.find(cond[i][0]);
		int b_idx = line.find(cond[i][2]);
		char comp = cond[i][3];
		int dist = atoi(&cond[i][4]);

		if (comp == '=') {
			if (!(abs(a_idx - b_idx) == dist + 1))
				return false;
		}
		else if (comp == '<') {
			if (!(abs(a_idx - b_idx) < dist + 1))
				return false;
		}
		else {
			if (!(abs(a_idx - b_idx) > dist + 1))
				return false;
		}
	}
	return true;
}

void order(string line, string friends) {
	if (friends.size() == 0) {
		if (!checkCondition(line)) {
			//cout << (line) << endl;
			Answer = Answer - 1;
		}
		return;
	}
	for (int i = 0; i < friends.size(); i++) {
		line += friends[i];
		string front = friends.substr(0, i);
		string end = friends.substr(i+1, friends.size());
		order(line, front + end);
		line.pop_back();
	}
	
}

int main() {	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cond[i];
	}

	order("", all_friends);
	cout << Answer << '\n';
	//string test = "NFRABCTE";
	//cin >> test;
	//if (checkCondition(test))
	//	cout << "yEs" << endl;
}