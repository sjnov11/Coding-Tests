#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	long long score;
	vector<int> child;
	int singer;
};

int N, K, J;
Node* node_list[100001];
int singer_cnt[100001];
long long singer_sum[100001];
long long singer_thresh[100001];
int singer_answer[100001];


// Tree의 크기를 반환한다.
int subtreeSize(Node* n) {
	int ret = 1;
	for (int i = 0; i < n->child.size(); i++) {
		ret += subtreeSize(node_list[n->child[i]]);
	}
	return ret;
}

// Tree를 탐색하면서 node에 해당하는 가수의 score를 더한다.
// 가수의 점수가 threshold를 넘으면 time을 체크해둔다.
void addScore(Node* n, int score, int time) {
	//n->score += score;
	if (singer_answer[n->singer] == 0) {
		singer_sum[n->singer] += score;
		if (singer_thresh[n->singer] < singer_sum[n->singer]) {
			//if (singer_answer[n->singer] == 0)
				singer_answer[n->singer] = time;
		}
	}
	for (int i = 0; i < n->child.size(); i++) {
		addScore(node_list[n->child[i]], score, time);
	}
}

int main() {
	cin >> N >> K >> J;

	// node_list 1~N까지 . 1 번 노래 부터 N번 노래까지
	for (int i = 1; i <= N; i++) {
		node_list[i] = new Node();
	}
	
	// node_list 부모. 1번이 루트니깐. 그 이후 2번부터 ~ N번 노래까지 부모 연결
	for (int i = 2; i <= N; i++) {
		int parent;
		cin >> parent;
		(node_list[parent]->child).push_back(i);
	}

	// 1~N번 노래의 가수저장. 가수의 노래 수 저장. 가수의 점수 threshold 저장. 
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		node_list[i]->singer = n;
		singer_cnt[n]++;
		singer_thresh[n] += J;
	}

	// K개의 데이터 정보
	// data[시간] = (노래번호, 가중치)

	vector<pair<int, int>> data = vector<pair<int, int>>(K + 1);
	for (int i = 1; i <= K; i++) {
		int T, P, S;
		cin >> T >> P >> S;
		data[T] = make_pair(P, S);
	}

	// root , score, time : root에서부터 자손노드의 가수 점수에 score를 더한다.
	// 가수 점수가 threshold 를 넘으면 time check.
	for (int i = 1; i <= K; i++) {
		int size = subtreeSize(node_list[data[i].first]);
		int score = (data[i].second / size);
		addScore(node_list[data[i].first], score, i);
	}
	for (int i = 1; i <= N; i++) {
		int t = singer_answer[node_list[i]->singer];
		cout << "i: " << i << " ";
		if (t == 0) {
			cout << "-1" << '\n';
		}
		else
			cout << t << '\n';
	}
}