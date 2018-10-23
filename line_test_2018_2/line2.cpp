#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <string>
#include <string.h>

using namespace std;
string **matrix;
bool ***visited;
pair<int, int> answer;

char turn(char cur_dir, char node_dir) {
	if (node_dir == 'F') {
		return cur_dir;
	}
	if (node_dir == 'R') {
		if (cur_dir == 'F') {
			return node_dir;
		}
		if (cur_dir == 'R') {
			return 'B';
		}
		if (cur_dir == 'L') {
			return 'F';
		}
		if (cur_dir == 'B') {
			return 'L';
		}
	}
	if (node_dir == 'L') {
		if (cur_dir == 'F') {
			return node_dir;
		}
		if (cur_dir == 'R') {
			return 'F';
		}
		if (cur_dir == 'L') {
			return 'B';
		}
		if (cur_dir == 'B') {
			return 'R';
		}
	}

	if (node_dir == 'B') {
		if (cur_dir == 'F') {
			return node_dir;
		}
		if (cur_dir == 'R') {
			return 'L';
		}
		if (cur_dir == 'L') {
			return 'R';
		}
		if (cur_dir == 'B') {
			return 'F';
		}
	}
}


void go(int x, int y, char cur_dir) {
	//visited[x][y] = true;
	char node_dir = matrix[x][y][0];
	int size = atoi(&matrix[x][y][1]);
	
	char next_dir = turn(cur_dir, node_dir);
	if (next_dir == 'F') {
		if (visited[x][y][0]) {
			answer.first = x;
			answer.second = y;
			return;
		}
		visited[x][y][0] = true;
		go(x, y - size, next_dir);
	}
	else if (next_dir == 'R') {
		if (visited[x][y][1]) {
			answer.first = x;
			answer.second = y;
			return;
		}
		visited[x][y][1] = true;
		go(x + size, y, next_dir);
	}
	else if (next_dir == 'L') {
		if (visited[x][y][2]) {
			answer.first = x;
			answer.second = y;
			return;
		}
		visited[x][y][2] = true;
		go(x - size, y, next_dir);
	}
	else {
		if (visited[x][y][3]) {
			answer.first = x;
			answer.second = y;
			return;
		}
		visited[x][y][3] = true;
		go(x, y + size, next_dir);
	}
}

int main() {
	int n;
	cin >> n;
	matrix = new string*[n];
	visited = new bool**[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new string[n];
		visited[i] = new bool*[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = new bool[4];
		}
	}
	
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			string node;
			cin >> node;
			matrix[y][x] = node;
			// @todo Write your code here.
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				visited[i][j][k] = false;
			}
		}
	}

	go(0, 0, 'B');
	a

	// @todo Write your code here.
	cout << answer.first << " " << answer.second<< endl;
	return 0;
}
