#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
int N, Q;


vector<pair<int, int>> checkpoints;
bool visited[250000];
vector<int> possible[250000];

vector<int> next(int a, int hp) {
	vector<int> ret;
	pair<int, int> cur = checkpoints[a];
	if (possible[a].size() > 0) return possible[a];
	for (int i = 0; i < checkpoints.size(); i++) {
		pair<int, int> pos = checkpoints[i];		
		if (visited[i]) continue;

		for (int j = -hp; j <= hp; j++) {
			if (pos.first == cur.first + j || pos.second == cur.second + j) {
				possible[a].push_back(i);
				ret.push_back(i);
			}
		}
	}
	return ret;
}

bool canMove(int a, int b, int hp) {
	queue<int> q;
	q.push(a);
	visited[a] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == b)
			return true;
		vector<int> n = next(cur, hp);
		for (int i = 0; i < n.size(); i++) {
			q.push(n[i]);
			visited[n[i]] = true;
		}
	}
	return false;
}


int main() {
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		checkpoints.push_back(make_pair(x, y));
	}

	for (int i = 0; i < Q; i++) {
		for (int j = 0; j < N; j++) {
			visited[j] = false;
		}
		int a, b, hp;
		cin >> a >> b >> hp;
		if (canMove(b-1, a-1, hp)) {
			cout << "YES" << '\n';
		}
		else 
			cout << "NO" << '\n';
	}
}