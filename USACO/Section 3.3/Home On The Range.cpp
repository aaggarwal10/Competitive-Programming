/*
ID: anish.51
PROB: range
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int dp[255][255] = {};
int grid[255][255] = {};
int N;
int countSquares[251] = {};
ifstream fin("range.in");
ofstream fout("range.out");

int main()
{
    fin >> N;
    char c;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            fin >> c;
            grid[i][j] = c-'0';
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if(grid[i][j]==0){
                dp[i][j] = 0;
            }
            else{
                int sumUp = 0;
                int sumLeft = 0;
                int change = 0;
                while(i+change>=1){
                    if(grid[i+change][j]==0){
                        break;
                    }
                    else{
                        sumUp++;
                        change--;
                    }
                }
                change = 0;
                while(j+change>=1){
                    if(grid[i][j+change]==0){
                        break;
                    }
                    else{
                        sumLeft++;
                        change--;
                    }
                }
                dp[i][j] = min(sumUp,sumLeft);
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    for(int i = 1; i<=N;i++){
        for(int j = 1; j<=N; j++){
            for(int sqSize = 2; sqSize<=dp[i][j]; sqSize+=1){
                countSquares[sqSize]++;
            }
        }
    }
    for(int i = 2; i<251; i++){
        if(countSquares[i]>0){
            fout << i << " " << countSquares[i] << endl;
        }
    }
    return 0;
}
