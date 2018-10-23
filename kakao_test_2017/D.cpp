#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void go(int n, int t, int m, vector<string>time_table) {
	priority_queue<pair<int, int>> pq;
	pair<int, int> answer;
	for (string time : time_table) {
		char h[2];
		char m[2];
		h[0] = time[0];	h[1] = time[1];
		m[0] = time[3]; m[1] = time[4];

		int hour = atoi(h);
		int min = atoi(m);
		
		pq.push({ hour*(-1), min*(-1) });
	}

	pair<int, int> cur = { 9, 0 };
	bool flag = false;
	pair<int, int> last;
	int enter_num;

	for (int i = 0; i < n; i++) {
		cur.second += i*t;
		if (cur.second >= 60) {
			cur.first += 1;
			cur.second -= 60;
		}
		enter_num = 0;
		for (int j = 0; j < m; j++) {
			// 대기 인원 < 총 탈 버스 인원 충분.. 마지막 버스를 타자.
			if (pq.size() == 0) {
				flag = true;
				break;
			}
			auto crew_time = pq.top();
			int crew_h = crew_time.first * (-1);
			int crew_m = crew_time.second * (-1);
			if (crew_h < cur.first) {
				last.first = crew_h;
				last.second = crew_m;
				enter_num++;
				pq.pop();
				continue;
			}
			else if (crew_h == cur.first && crew_m <= cur.second) {
		  		last.first = crew_h;
				last.second = crew_m;
				enter_num++;
				pq.pop();
				continue;
			}
		}
		// 버스가 충분하니 마지막꺼 
		if (flag) {
			answer.first = 9;
			answer.second = t*(n - 1);
			while (answer.second >= 60) {
				answer.second -= 60;
				answer.first += 1;
			}
			break;
		}
	}
	if (enter_num < m) {
		answer.first = 9;
		answer.second = t*(n - 1);
		while (answer.second >= 60) {
			answer.second -= 60;
			answer.first += 1;
		}
	}
	else {
		answer.first = last.first;
		answer.second = last.second - 1;
		if (answer.second < 0) {
			answer.first--;
			answer.second = 59;
		}
	}
	printf("%02d:%02d\n", answer.first, answer.second);
}


int main() {
	int n, t, m;
	vector<string> time_table;

	/*n = 1;
	t = 1;
	m = 5;
	time_table.resize(4);
	time_table = { "08:00", "08:01", "08:02", "08:03" };
	go(n, t, m, time_table);*/

	/*n = 2;
	t = 10;
	m = 2;
	time_table.resize(3);
	time_table = { "09:10", "09:09", "08:00" };
	go(n, t, m, time_table);*/

	/*n = 2;
	t = 1;
	m = 2;
	time_table.resize(4);
	time_table = { "09:00", "09:00", "09:00", "09:00" };
	go(n, t, m, time_table);*/

	/*n = 1;
	t = 1;
	m = 5;
	time_table.resize(5);
	time_table = { "00:01", "00:01", "00:01", "00:01", "00:01" };
	go(n, t, m, time_table);*/

	/*n = 1;
	t = 1;
	m = 1;
	time_table.resize(1);
	time_table = { "23:59" };
	go(n, t, m, time_table);*/

	n = 10;
	t = 60;
	m = 45;
	time_table.resize(16);
	time_table = { "23:59","23:59","23:59","23:59","23:59","23:59","23:59",
					"23:59","23:59","23:59","23:59","23:59","23:59","23:59",
					"23:59", "23:59", };
	go(n, t, m, time_table);

}