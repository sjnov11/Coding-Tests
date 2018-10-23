#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


int N, Q;

// checkpoint 좌표, 방문 여부.
map<pair<int, int>, int> check;
vector<pair<int, int>> t;

double dist(pair<int, int>a, pair<int, int>b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

vector<pair<int, int>> possiblePos(pair<int, int> a, int hp) {
	vector<pair<int, int>> ret;
	map<pair<int, int>, int>::iterator it;
	for (it = check.begin(); it != check.end(); ++it) {
		pair<int, int> pos = make_pair(it->first.first, it->first.second);
		int visited = it->second;
		if (!visited) continue;

		if (pos.first == a.first && pos.second != a.second) {
			ret.push_back(pos);
		}
		else if (pos.first != a.first && pos.second == a.second) {
			ret.push_back(pos);
		}
		else {
			for (int i = -hp; i <= hp; i++) {
				if (i == 0) continue;
				if (a.first + i == pos.first)
					ret.push_back(pos);
				else if (a.second + i == pos.second)
					ret.push_back(pos);
			}
			
		}
	}
	return ret;
}


bool canMove(pair<int,int> a, pair<int,int>b, int hp) {
	if (a == b) {
		//check.find(a)->second = 1;
		return true;
	}
	bool ret = false;

	
	check.find(a)->second = 0; // visited 체크
	vector<pair<int, int>> p = possiblePos(a, hp);
	// p = 0일때는?

	for (int i = 0; i < p.size(); i++) {		
		//if (p[i].first == a.first || p[i].second == a.second) {
			if (canMove(p[i], b, hp)) {
				check.find(a)->second = 1;
				return true;
			}
		//}
		//else {
		//	if (canMove(p[i], b, hp)) {
		//		check.find(a)->second = 1;
		//		return true;
		//	}
		//}
		//check.find(p[i])->second = 1;
	}
	check.find(a)->second = 1;
	return false;

}
int main() {
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		check.insert(make_pair(make_pair(x, y), 1));
		t.push_back(make_pair(x, y));
	}
	bool answer;
	for (int i = 0; i < Q; i++) {
		int a, b, hp;
		cin >> a >> b >> hp;
		map<pair<int, int>, int > ::iterator it;
		/*for (it = check.begin(); it != check.end(); ++it) {
			cout << it->first.first << ","<< it->first.second << ": " << it->second <<endl;
		}*/
		answer = canMove(t[a - 1], t[b - 1], hp);
		if (answer)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		
	}
	
	return 0;
}