#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b) {
	if (a.first > b.first) 
		return true;
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return false;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> stay_list(N + 2, 0);
	vector<pair<double,int>> fail_list(N);
	vector<int> answer;
	int total = stages.size();
	for (auto s : stages) {
		stay_list[s]++;
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += stay_list[i];
		if (total - sum == 0) {
			fail_list[i].first = 0;
			fail_list[i].second = i;
		}
		else {
			fail_list[i].first = (double)stay_list[i + 1] / (double)(total - sum);
			fail_list[i].second = i;
		}
	}
	sort(fail_list.begin(), fail_list.end(),cmp);
	for (auto f : fail_list) {
		answer.push_back(f.second + 1);
	}
	
	return answer;
}

int main() {
	int N= 5;
	vector<int> stages(8);
	stages = { 2,1,2,6,2,4,3,3
	};
	vector<int> a = solution(N, stages);

	
}