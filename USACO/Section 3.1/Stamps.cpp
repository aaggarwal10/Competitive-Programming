/*
ID: anish.51
PROB: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

const long INF = 2000005;
int dp[INF];
int K,N;
int coins[55]={0};
int index=1;

ifstream fin("stamps.in");
ofstream fout("stamps.out");

int main()
{
    fin >> K >> N;
    for(int i = 0;i<N;i++){
        fin>>coins[i];
    }
    for(int i = 0; i<INF; i++){
        dp[i] = INF;
    }
    dp[0] = 0;
    while (1){
        long minInSet = INF;
        for(int i = 0; i<N; i++){
            if(index-coins[i]>=0){
                if(minInSet>dp[index-coins[i]]+1){
                    minInSet = dp[index-coins[i]]+1;
                }
            }
        }
        if (minInSet>K){
            break;
        }
        dp[index] = minInSet;
        index++;
    }
    fout << --index << endl;
    return 0;
}
