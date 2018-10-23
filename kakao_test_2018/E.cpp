#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	int x;
	int y;
	int num;
	Node* left;
	Node* right;
};

//struct cmp {
//	bool operator ()(Node a, Node b) {
//		return a.y > b.y;
//	}
//};

bool cmp(Node a, Node b) {
	return a.y > b.y;
}

void preorder(Node* n, vector<int> &result) {
	if (n == NULL) {
		return;
	}
	result.push_back(n->num + 1);
	preorder(n->left, result);
	preorder(n->right, result);
}

void postorder(Node* n, vector<int> &result) {
	if (n == NULL) {
		return;
	}	
	postorder(n->left, result);
	postorder(n->right, result);
	result.push_back(n->num + 1);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<Node> node_list;
	for (int i = 0; i < nodeinfo.size(); i++) {
		node_list.push_back({ nodeinfo[i][0], nodeinfo[i][1], i, 0, 0});
	}
	sort(node_list.begin(), node_list.end(), cmp);
	
	Node* root = &node_list[0];

	for (int i = 1; i < node_list.size(); i++) {
		Node* cur = &node_list[i];
		Node* n = root;
		while (true) {
			if (n->x > cur->x) {
				if (n->left == NULL) {
					n->left = cur;
					break;
				}
				else 
					n = n->left;				
			}
			else {
				if (n->right == NULL) {
					n->right = cur;
					break;
				}
				else n = n->right;
			}
		}		

	}
	vector<vector<int>> answer;

	vector<int> pre;
	vector<int> post;
	preorder(root, pre);
	postorder(root, post);
	answer.push_back(pre);
	answer.push_back(post);
	return answer;
}

int main() {
	vector<vector<int>> nodeinfo = 
	{ {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} };
	solution(nodeinfo);
}