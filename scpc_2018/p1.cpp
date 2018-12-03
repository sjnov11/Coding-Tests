/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <set>
//#include <time.h>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);
	int T, test_case;
	cin >> T;
	// clock_t start, end;
	// start = clock();
	for(test_case = 0; test_case  < T; test_case++)
	{
		set<int> ability_set;
		int N, K;
		scanf("%d", &N);
		scanf("%d", &K);
		//cin >> N >> K;
		Answer = 0;
		for (int i = 0; i < N; i++) {
			int ability_num;
			scanf("%d", &ability_num);
			//cin >> ability_num;
			
			ability_set.insert(ability_num);
		}

		while (!ability_set.empty()) {
			int cur;
			set<int>::iterator it;		
			it = ability_set.begin();
			cur = *it;
			ability_set.erase(it);
			Answer++;

			while (true) {
				it = ability_set.lower_bound(cur + K + 1);
				if (it != ability_set.end()){
					cur = *it;
					ability_set.erase(it);
				}
				else {
					break;
				}
			}
		}
		printf("Case #%d\n", test_case+1);
		printf("%d\n", Answer);
		// cout << "Case #" << test_case+1 << endl;
		// cout << Answer << endl;
	}	
	// end = clock();
	// cout << ((double)(end-start)/CLOCKS_PER_SEC)<<endl;
	return 0;//Your program should return 0 on normal termination.
}