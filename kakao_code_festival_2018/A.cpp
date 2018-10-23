#include <iostream>
using namespace std;

int price1[6] = { 500, 300, 200, 50, 30, 10 };
int price2[5] = { 512, 256, 128, 64, 32 };

int T;

int total(int a, int b) {
	int p1 = 0, p2 = 0;
	
	if (a <= 21) p1 = price1[5];
	if (a <= 15) p1 = price1[4];
	if (a <= 10) p1 = price1[3];
	if (a <= 6) p1 = price1[2];
	if (a <= 3) p1 = price1[1];
	if (a <= 1) p1 = price1[0];
	if (a == 0) p1 = 0;
	if (b <= 31) p2 = price2[4];
	if (b <= 15) p2 = price2[3];
	if (b <= 7) p2 = price2[2];
	if (b <= 3) p2 = price2[1];
	if (b <= 1) p2 = price2[0];
	if (b == 0) p2 = 0;

	return (p1 + p2) *10000;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int a, b;
		cin >> a >> b;
		
		cout << total(a, b) << '\n';
	}
}