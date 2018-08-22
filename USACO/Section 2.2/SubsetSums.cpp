/*
ID: anish.51
LANG: C++
TASK: subset
*/
#include <iostream>
#include <fstream>
using namespace std;
int N;
int sumOfSet;
long long ansCache[800][40];
long long RecSearchDP(int n, int k){
    if (n<0 || k<0){
        return 0;
    }
    if (ansCache[n][k]!=-1){
        return ansCache[n][k];
    }
    ansCache[n][k] = RecSearchDP(n,k-1)+RecSearchDP(n-k,k-1);
    return ansCache[n][k];

}
int main()
{
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    for(int i = 0; i<800; i++){
        for(int j = 0; j<40; j++){
            ansCache[i][j] = -1;
        }
    }
    ansCache[0][0] = 1;
    fin >> N;
    sumOfSet = N*(N+1)/2;
    if(sumOfSet%2!=0){
        fout << 0 << endl;
    }
    else{
        fout << RecSearchDP(sumOfSet/2,N)/2 << endl;
    }

}
