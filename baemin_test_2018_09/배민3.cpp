#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


int solution(vector<int> &A, vector<int> &B, int M, int X, int Y) {
	// write your code in C++14 (g++ 6.2.0)
	int idx = 0;
	int cnt;
	int weight;
	int answer = 0;
	while (idx < A.size()) {
		cnt = 0;
		weight = 0;
		set<int> stop_floor;
		while (idx < A.size() && cnt + 1 <= X && weight + A[idx] <= Y) {
			stop_floor.insert(B[idx]);
			weight += A[idx];
			idx++;
			cnt++;
		}
		answer += stop_floor.size() + 1;
	}
	return answer;
}

int main() {
	vector<int> A;
	vector<int> B;
	A = { 40,40,100,80,20 };
	B = { 3,3,2,2,3 };
	solution(A, B, 3, 5, 200);
}