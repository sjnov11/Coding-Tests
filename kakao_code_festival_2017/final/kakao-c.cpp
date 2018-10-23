#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int m, n;
char board[101][101];
vector<pair<int, int>> alpha_pair_pos[27];
string Answer;
bool canDestroy(vector<pair<int, int>> pair_pos) {
	int x1, y1, x2, y2;
	int tx , ty, dx, dy;
	x1 = pair_pos[0].first, y1 = pair_pos[0].second;
	x2 = pair_pos[1].first, y2 = pair_pos[1].second;

	dx = abs(x1 - x2);
	dy = abs(y1 - y2);

	
	bool ret;;

	if (x1 >= x2 && y1 >= y2) {		
		// First x, Second y
		ret = true;
		tx = x1, ty = y1;
		for (int i = 1; i <= dx; i++) {
			tx--;
			if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
				ret = false;
				break;
			}
		}
		if (ret) {
			for (int i = 1; i <= dy; i++) {
				ty--;
				if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
					ret = false;
					break;
				}
			}
		}
		if (ret) return true;
		
		// First y, Second x
		ret = true;
		tx = x1, ty = y1;
		for (int i = 1; i <= dy; i++) {
			ty--;
			if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
				ret = false;
				break;
			}
		}		
		if (ret) {
			for (int i = 1; i <= dx; i++) {
				tx--;
				if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
					ret = false;
					break;
				}
			}
		}
		if (ret) return true;
	}

	else if (x1 >= x2 && y1 < y2) {
		// First x, Second y
		ret = true;
		tx = x1, ty = y1;
		for (int i = 1; i <= dx; i++) {
			tx--;
			if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
				ret = false;
				break;
			}
		}
		if (ret) {
			for (int i = 1; i <= dy; i++) {
				ty++;
				if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
					ret = false;
					break;
				}
			}
		}
		if (ret) return true;

		// First y, Second x
		ret = true;
		tx = x1, ty = y1;
		for (int i = 1; i <= dy; i++) {
			ty++;
			if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
				ret = false;
				break;
			}
		}
		if (ret) {
			for (int i = 1; i <= dx; i++) {
				tx--;
				if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
					ret = false;
					break;
				}
			}
		}
		if (ret) return true;
	}

	else if (x1 < x2 && y1 >= y2) {
		// First x, Second y
		ret = true;
		tx = x1, ty = y1;
		for (int i = 1; i <= dx; i++) {
			tx++;
			if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
				ret = false;
				break;
			}
		}
		if (ret) {
			for (int i = 1; i <= dy; i++) {
				ty--;
				if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
					ret = false;
					break;
				}
			}
		}
		if (ret) return true;

		// First y, Second x
		ret = true;
		tx = x1, ty = y1;
		for (int i = 1; i <= dy; i++) {
			ty--;
			if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
				ret = false;
				break;
			}
		}
		if (ret) {
			for (int i = 1; i <= dx; i++) {
				tx++;
				if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
					ret = false;
					break;
				}
			}
		}
		if (ret) return true;
	}

	else if (x1 < x2 && y1 < y2) {
		// First x, Second y
		ret = true;
		tx = x1, ty = y1;
		for (int i = 1; i <= dx; i++) {
			tx++;
			if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
				ret = false;
				break;
			}
		}
		if (ret) {
			for (int i = 1; i <= dy; i++) {
				ty++;
				if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
					ret = false;
					break;
				}
			}
		}
		if (ret) return true;

		// First y, Second x
		ret = true;
		tx = x1, ty = y1;
		for (int i = 1; i <= dy; i++) {
			ty++;
			if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
				ret = false;
				break;
			}
		}
		if (ret) {
			for (int i = 1; i <= dx; i++) {
				tx++;
				if (board[tx][ty] != '.' && board[tx][ty] != board[x1][y1]) {
					ret = false;
					break;
				}
			}
		}
		if (ret) return true;
	}
	return false;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char t;
			cin >> t;
			board[i][j] = t;
			if (t - 'A' >= 0 && 'Z' - t >= 0) {
				alpha_pair_pos[t - 'A'].push_back(make_pair(i, j));
			}
		}
	}
	while (true) {
		bool remove = false;
		for (int i = 0; i < 27; i++) {
			if (alpha_pair_pos[i].empty()) continue;
			if (canDestroy(alpha_pair_pos[i])) {
				int x1, y1, x2, y2;
				x1 = alpha_pair_pos[i][0].first, y1 = alpha_pair_pos[i][0].second;
				x2 = alpha_pair_pos[i][1].first, y2 = alpha_pair_pos[i][1].second;
				board[x1][y1] = '.';
				board[x2][y2] = '.';
				alpha_pair_pos[i].clear();
				remove = true;
				Answer+= char(i + 'A');
				break;
			}
		}
		if (!remove) break;
	}

	for (int i = 0; i < 27; i++) {
		if (!alpha_pair_pos[i].empty()) {
			cout << "IMPOSSIBLE" << '\n';
			return 0;
		}
	}

	cout << Answer << '\n';
	
	return 0;
}