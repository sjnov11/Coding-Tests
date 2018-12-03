/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <stdlib.h>
using namespace std;

class Node {
public:
    int val;
    bool visited;
    //list<Node*> neighbors_list;
    set<int> neightbor_num_set;

    Node() {

    }
    Node(int v) {
        val = v;
        visited = false;
    }
};

vector<Node*> node_list;
int Answer;
void findTriCycle(Node* n) {
    if (n->visited) return;
    set<int>::iterator it_1, it_2;
    for (it_1 = n->neightbor_num_set.begin(); it_1 != n->neightbor_num_set.end(); ++it_1) {        
        Node* n1 = node_list[*it_1];
        if (n1->visited) continue;
        for (it_2 = n1->neightbor_num_set.begin(); it_2 != n1->neightbor_num_set.end(); ++it_2) {
            Node* n2 = node_list[*it_2];
            if (n2->visited) continue;
            if (n2->neightbor_num_set.find(n->val) != n2->neightbor_num_set.end()) {
                if (n2->neightbor_num_set.size() == 2) {
                    n2->visited = true;
                    //cout << "remove " << n2->val << endl;
                    Answer++;
                }
                else if (n1->neightbor_num_set.size() == 2) {
                    n1->visited = true;
                    //cout << "remove " << n1->val << endl;
                    Answer++;
                }
                else if (n->neightbor_num_set.size() == 2) {
                    n->visited = true;
                    //cout << "remove " << n->val << endl;
                    Answer++;
                    return;
                }
            }
        }
    }
    n->visited = true;
}



int main(int argc, char** argv)
{
	int T, test_case;
	setbuf(stdout, NULL);

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
        
        node_list.clear();
        Node* n = new Node();
        node_list.push_back(n);

        int N, M;

        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++) {
            n = new Node(i);
            node_list.push_back(n);
        }

        for (int i = 0; i < M; i++) {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            //cout << node_list[n1]->val << endl;
            node_list[n1]->neightbor_num_set.insert(n2);
            node_list[n2]->neightbor_num_set.insert(n1);
        }
        
        for (int i = 1; i <=N; i++) {
            findTriCycle(node_list[i]);
        }
		
		// cout << "Case #" << test_case+1 << endl;
		// cout << N - Answer << endl;
        printf("Case #%d\n", test_case+1);
        printf("%d\n", N - Answer);

        for (int i = 0; i<=N; i++) {
            Node* t = node_list[i];
            free(t);
        }
	}

	return 0;//Your program should return 0 on normal termination.
}