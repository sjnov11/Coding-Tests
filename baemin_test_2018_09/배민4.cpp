#include <iostream>
#include <vector>

using namespace std;


int solution(vector<int>& A, int X) {
	int N = A.size();
	if (N == 0) {
		return -1;
	}
	int l = 0;
	int r = N - 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (A[m] == X) return m;
		if (A[m] > X) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	if (A[l] == X) {
		return l;
	}
	return -1;
}

int main() {
	vector<int> A;
	int B;
	A = { 1 };
	B = 1;
	//A = { -9, -8, -5, -4, -1, 1, 2, 9 };
	//B = 7;
	cout << solution(A,B) << endl;
}