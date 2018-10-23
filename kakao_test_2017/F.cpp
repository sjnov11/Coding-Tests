#include <iostream>
#include <vector>
#include <string>
using namespace std;

void go(int m, int n, char* board_2[]) {
	int answer = 0;
	char board[31][31];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = board_2[i][j];
		}
	}

	while (true) {
		vector<pair<int, int>> remove_list;
		for (int i = 0; i + 1 < m; i++) {
			for (int j = 0; j + 1 < n; j++) {
				char s1 = board[i][j];
				char s2 = board[i][j + 1];
				char s3 = board[i + 1][j];
				char s4 = board[i + 1][j + 1];
				if (s1 == s2 && s2 == s3 && s3 == s4 && s4 != 'x') {
					remove_list.push_back({ i,j });
				}
			}
		}
		if (remove_list.size() == 0) {
			break;
		}
		for (auto pos : remove_list) {
			int r = pos.first;
			int c = pos.second;
			if (board[r][c] != 'x') {
				board[r][c] = 'x';
				answer++;
			}
			if (board[r][c + 1] != 'x') {
				board[r][c + 1] = 'x';
				answer++;
			}
			if (board[r + 1][c] != 'x') {
				board[r + 1][c] = 'x';
				answer++;
			}
			if (board[r + 1][c + 1] != 'x') {
				board[r + 1][c + 1] = 'x';
				answer++;
			}
		}



		for (int j = 0; j < n; j++) {
			for (int i = m - 1; i >= 0; i--) {
				if (board[i][j] == 'x') {
					int r = i;
					while (board[r][j] == 'x' && r >= 0) {
						r--;
					}
					int dr = 0;
					if (r < 0) break;
					while (true) {
						if (r < 0) break;
						board[i + dr][j] = board[r][j];
						board[r][j] = 'x';
						dr--;
						r--;
					}
				}
			}
		}
	}
	cout << answer << endl;
}



int main() {
	int m, n;
	
	/*m = 4;
	n = 5;
	char* board[4] = { "CCBDE", "AAADE", "AAABF", "CCBBF" };*/

	m = 6;
	n = 6;
	char* board[6] = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };

	go(m, n, board);
}