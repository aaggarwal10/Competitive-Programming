/*
ID: anish.51
PROB: inflate
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int dp[10001] = {0};
int M,N,points,minutes;

int main()
{
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    fin >> M >> N;
    for(int i = 0; i<N; i++){
        fin >> points >> minutes;
        for(int j = minutes; j<=M; j++){
            dp[j] = max(dp[j],dp[j-minutes]+points);
        }
    }

    fout<< dp[M] << endl;

    return 0;
}
