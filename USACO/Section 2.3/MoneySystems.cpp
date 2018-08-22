/*
ID: anish.51
PROB: money
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int V,N;
vector<int> coins;
int main()
{
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    fin >> V >> N;
    long long coinDP[N+1][V];

    for(int i = 0; i<V;i++){
        int val;
        fin >> val;
        coins.push_back(val);

        coinDP[0][i] = 1;

    }

    for(int i=1;i<N+1;i++){
        for(int j = 0; j<V; j++){
            long long x=0,y=0;
            if(i-coins[j]>=0){
                x = coinDP[i-coins[j]][j];
            }
            if(j>0){
                y = coinDP[i][j-1];
            }
            coinDP[i][j] = x + y;
        }
    }

    fout << coinDP[N][V-1] << endl;
}
