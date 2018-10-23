#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	int money = 20000;
	for (int distance; !(ss >> distance).fail(); ) {

		// @todo Write your code here.
		//if (distance <= 40) sum += 720;
		int sum = 720;
		if (distance < 4 || distance > 178) {
			cout << money << endl;
			return 0;
		}
		if (distance > 40) {
			int div = (distance - 40) / 8;
			int mod = (distance - 40) % 8;
			//cout << div << "/ " << mod << endl;
			sum += (div + (mod == 0 ? 0 : 1)) * 80;
		}
		money -= sum;
		if (money < 0) {
			cout << money + sum << endl;
			return 0;
		}
	}
	// @todo Write your code here.
	cout << money << endl;
	return 0;
}
