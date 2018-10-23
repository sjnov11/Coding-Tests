#include <iostream>
using namespace std;

int m, n;
int city_map[500][500];
int dp[500][500];

int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city_map[i][j];
		}
	}
	dp[0][0] = 1;

	for (int i = 0; i < m; i++) {
		for (int j = i == 0 ? 1 : 0; j < n; j++) {
			if (city_map[i][j] == 1) continue;
			int up = i - 1;
			int left = j - 1;

			if (up >= 0) {
				while (city_map[up][j] == 2) up--;
				dp[i][j] += dp[up][j];
			}

			if (left >= 0) {
				while (city_map[i][left] == 2) left--;
				dp[i][j] += dp[i][left];
			}
		}
	}

	cout << dp[m - 1][n - 1] << '\n';
}