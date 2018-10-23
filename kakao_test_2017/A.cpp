#include <iostream>
#include <cstring>
using namespace std;

void go(int n, int arr1[], int arr2[]) {
	int map1[16][16], map2[16][16];

	memset(map1, 0, sizeof(int) * 16 * 16);
	memset(map2, 0, sizeof(int) * 16 * 16);

	for (int i = 0; i < n; i++) {
		cout << "row " << i << endl;
		for (int j = 0; j < n; j++) {
			cout << n-j-1<< " : " << arr1[i] << " / " << arr1[i] % 2<< endl;
			map1[i][n - j - 1] = arr1[i] % 2;
			arr1[i] /= 2;
			if (arr1[i] == 0) break;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map2[i][n - j - 1] = arr2[i] % 2;
			arr2[i] /= 2;
			if (arr2[i] == 0) break;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map1[i][j] | map2[i][j])
				cout << "#";
			else
				cout << " ";
		}
		cout << "\n";
	}
}


int main() {
	/*int n = 5;
	int arr1[5] = { 9, 20, 28, 18, 11 };
	int arr2[5] = { 30, 1, 21, 17, 28 };*/
	int n = 6;
	int arr1[6] = { 46, 33, 33, 22, 31, 50 };
	int arr2[6] = { 27, 56, 19, 14, 14, 10 };
	go(n, arr1, arr2);
}