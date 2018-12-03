/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Answer;
vector<int> Answer_list;

int createPalindrome(int input, bool isOdd) {
    int n = input;
    int palindrome = input;
    if (isOdd) {
        n /= 10;
    }
    while (n > 0) {
        palindrome = palindrome * 10 + (n % 10);
        n /= 10;
    }
    return palindrome;
}

vector<int> palindromeList(int n) {
    vector<int> palindrome_list;

    int pal;

    for (int j = 0; j < 2; j++) {
        int i = 1;
        while ( (pal = createPalindrome(i, j)) <= n) {
            palindrome_list.push_back(pal);
            i++;
        }
    }
   
    sort(palindrome_list.begin(),palindrome_list.end(), greater<int>());
    return palindrome_list;
}

void solve(int num, int cnt) {

    vector<int> palindrome_list = palindromeList(num);
    vector<int>::iterator i, j, k ,l;
    
    for (i = palindrome_list.begin(); i!=palindrome_list.end(); ++i) {
        int temp = num;
        temp -= *i;
        if (temp == 0) {
            //printf("1 %d\n", *i);
            Answer_list.push_back(*i);
            return;
        }        
        for (j = i; j!=palindrome_list.end(); ++j) {
            if (temp - *j < 0) {
                continue;
            }
            if (temp -*j == 0) {
                //printf("2 %d %d\n", *i, *j);
                Answer_list.clear();
                Answer_list.push_back(*j);
                Answer_list.push_back(*i);
                return;
            }
            temp -= *j;
            for (k = j; k!=palindrome_list.end();++k) {
                if (temp-*k < 0) {
                    continue;
                }
                if (temp -*k == 0) {
                    // printf("3 %d %d %d\n", *i, *j, *k);
                    // return;
                    //if (Answer_list.size() == 0 || Answer_list.size() > )
                    if (Answer_list.size() == 0) {
                        Answer_list.push_back(*k);
                        Answer_list.push_back(*j);
                        Answer_list.push_back(*i);
                    }
                }
                temp += *k;               
            }
            temp +=*j;
        }
        temp += *i;
    }    
}

int main(int argc, char** argv)
{
	int T, test_case;
	

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        Answer_list.clear();
        int n;
        scanf("%d", &n);

        //vector<int> palindrome_list = palindromeList(n);
        //bool ret;
        //ret = solve(n, 0);
        printf("Case #%d\n", test_case+1);
        // if (ret) {
        //     Answer = Answer_list.size();
        //     printf("%d ", Answer);
        //     sort(Answer_list.begin(), Answer_list.end(), greater<int>());
        //     for (int i = 0; i < Answer_list.size(); i++) {
        //         printf("%d ", Answer_list[i]);
        //     }
        //     printf("\n");
        // }
        // else {
        //     printf("0\n");
        // }
        solve(n, 0);
        
        if (Answer_list.size() == 0) 
            printf("0\n");

        else {
            sort(Answer_list.begin(), Answer_list.end(), greater<int>());
            printf("%d ", Answer_list.size());
            for (int i = 0; i < Answer_list.size(); i++) {
                printf("%d ",Answer_list[i]);
            }
            printf("\n");
        }

		// cout << "Case #" << test_case+1 << endl;
		// cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}