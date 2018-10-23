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


// Tree�� ũ�⸦ ��ȯ�Ѵ�.
int subtreeSize(Node* n) {
	int ret = 1;
	for (int i = 0; i < n->child.size(); i++) {
		ret += subtreeSize(node_list[n->child[i]]);
	}
	return ret;
}

// Tree�� Ž���ϸ鼭 node�� �ش��ϴ� ������ score�� ���Ѵ�.
// ������ ������ threshold�� ������ time�� üũ�صд�.
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

	// node_list 1~N���� . 1 �� �뷡 ���� N�� �뷡����
	for (int i = 1; i <= N; i++) {
		node_list[i] = new Node();
	}
	
	// node_list �θ�. 1���� ��Ʈ�ϱ�. �� ���� 2������ ~ N�� �뷡���� �θ� ����
	for (int i = 2; i <= N; i++) {
		int parent;
		cin >> parent;
		(node_list[parent]->child).push_back(i);
	}

	// 1~N�� �뷡�� ��������. ������ �뷡 �� ����. ������ ���� threshold ����. 
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		node_list[i]->singer = n;
		singer_cnt[n]++;
		singer_thresh[n] += J;
	}

	// K���� ������ ����
	// data[�ð�] = (�뷡��ȣ, ����ġ)

	vector<pair<int, int>> data = vector<pair<int, int>>(K + 1);
	for (int i = 1; i <= K; i++) {
		int T, P, S;
		cin >> T >> P >> S;
		data[T] = make_pair(P, S);
	}

	// root , score, time : root�������� �ڼճ���� ���� ������ score�� ���Ѵ�.
	// ���� ������ threshold �� ������ time check.
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