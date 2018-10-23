/*
	KAKAO CODE FESTIVAL 2017 ROUND1 - A
	URL : http://tech.kakao.com/2017/08/11/code-festival-round-1/
*/

#include <iostream>
#include <algorithm>
using namespace std;

int picture[100][100];
int checked[100][100];
int m, n;
int max_size = 0;
int max_color = 0;
int cnt = 0;


int search(int x, int y) {
	int value = picture[x][y];
	checked[x][y] = true;
	
	int up=0, down=0, left=0, right=0;
	
	// Up
	if (x - 1 >= 0 && picture[x - 1][y] == value && checked[x - 1][y] == false) {
		up = search(x - 1, y);
	}
	// Down
	if (x + 1 < m && picture[x + 1][y] == value && checked[x + 1][y] == false) {
		down = search(x + 1, y);
	}
	// Left
	if (y - 1 >= 0 && picture[x][y - 1] == value && checked[x][y - 1] == false) {
		left = search(x, y-1);
	}
	// Right
	if (y + 1 < n && picture[x][y + 1] == value && checked[x][y + 1] == false) {
		right = search(x, y + 1);
	}

	return up + down + left + right + 1;
}



int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> picture[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (checked[i][j]) continue;
			if (picture[i][j] == 0) continue;
			int size = search(i, j);
			cnt++;
			if (max_size < size) {
				max_size= size;
				max_color = picture[i][j];
			}
		}
	}
	cout << cnt << ", " << max_size << '\n';

}