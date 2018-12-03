#include <iostream>
#include <fstream>
#include <set>
using namespace std;


int main (){
    ofstream outFile("testcase.txt");
    outFile << "1" << endl;
    outFile << "200000 199999" << endl;
    

    
        
        for (int i = 1; i < 200000; i++) {
            outFile << i << " " << i+1 << endl;
        }    
    

   

}