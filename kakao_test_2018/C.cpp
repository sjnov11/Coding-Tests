#include <string>
#include <vector>
#include <iostream>
#include <set>
#include<algorithm>
using namespace std;

void go(vector<vector<string>> relation, int cur, int set_size, int selected, 
	vector<string> key, vector<int> key_set, vector<vector<int>> &answer) {
	if (selected == set_size) {
		set<string> temp;
		bool possible = true;
		for (string s : key) {
			if (!temp.insert(s).second) {
				possible = false;
				break;
			}
		}
		if (!possible) return;
		
		bool test;
		if (answer.size() == 0) test = true;
		for (int i = 0; i < answer.size(); i++) {
			test = false;
			for (int j = 0; j < answer[i].size(); j++) {
				if (answer[i][j] == 1 && key_set[j] != 1) {
						test = true;
						break;
				}
			}
			if (!test) break;
		}
		if (test) {
			answer.push_back(key_set);
		}
		
		
		return;
	}
	if (cur >= relation[0].size()) {
		return;
	}

	go(relation, cur + 1, set_size, selected, key, key_set, answer);

	//vector<string> cur_col; 
	//for (int i = 0; i < relation.size(); i++) {
	//	cur_col.push_back(relation[i][cur]);
	//}
	for (int i = 0; i < relation.size(); i++) {
		key[i] += relation[i][cur]+",";
	}
	key_set[cur] = 1;
	go(relation, cur + 1, set_size, selected + 1, key, key_set, answer);
	
}

void go2(vector<vector<string>> relation, int select_num, int cur, int selected,
	vector<string> selected_col_s, vector<int> selected_col_num) {
	if (select_num == selected) {
		
	}



	go2(relation, select_num, cur + 1, selected, selected_col_s, selected_col_num);

	for (int i = 0; i < relation.size(); i++) {
		selected_col_s[i] += relation[i][cur];
	}

	go2(relation, select_num, cur + 1, selected + 1, selected_col_s, selected_col_num);

}

int solution(vector<vector<string>> relation) {
	vector<vector<int>> set_list;
	vector<string> one_col_row(relation.size());
	vector<int> selected_col(relation[0].size());

	for (int i = 1; i <= relation[0].size(); i++) {
		go(relation, 0, i, 0, one_col_row, selected_col, set_list);
	}
	int answer = set_list.size();
	//cout << set_list.size() << endl;
	return answer;
}

int main() {
	vector<vector<string>> a =

		{{"100", "ryan1", "music1", "25"},
		{"100", "ryan1", "music1", "24"},
		{"100", "ryan1", "music2", "25"},
		{"100", "ryan2", "music1", "25"},
		{"200", "ryan1", "music1", "25"}};

	/*vector<vector<string>> b;

	vector<string> key(6);
	vector<int>key_set(4);
	vector<vector<int>> answer;
	go(a, 0, 2, 0, key, key_set, answer);

	for (auto v : answer) {
		for (auto c : v) {
			cout << c << " ";
		}
		cout << endl;
	}*/
	solution(a);
}