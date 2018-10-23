#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int next_fork[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 1001; i++) {
		next_fork[i] = -1;
	}
	//cout << n << endl;
	while (n-- >= 0) {
		string line;
		getline(cin, line);  // drop a newline traling n
		stringstream ss(line);
		int before = 0;
		for (int fork; !(ss >> fork).fail(); ) {  // read forks from a note
			//cout << fork << endl;
			if (next_fork[fork] == -1) next_fork[fork] = 0;
			next_fork[before] = fork;
			before = fork;
		}
		// @todo Write your code here.
	}
	// @todo Write your code here.
	for (int i = 1; i <= 1000; i++) {
		if (next_fork[i] == 0)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}
