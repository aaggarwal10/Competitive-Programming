/*
ID: anish.51
LANG: C++
TASK: numtri
*/
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int N;
int dp [1001][1001];
int maxSum = 0;
int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    fin >> N;
    //set tables to default -1
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            dp[i][j] = -1;
        }
    }
    //make table
    for (int i = 0; i<N; i++){
        for (int j = 0; j<=i;j++){
            fin >> dp[i-j][j];
        }
    }
    //loop through and get maximum sum of table
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            if (dp[i][j]!=-1){
                if (i == 0 && j == 0){
                    continue;
                }
                else if (i == 0){
                    dp[i][j] += dp[i][j-1];
                }
                else if(j == 0){
                    dp[i][j] += dp[i-1][j];
                }
                else{
                    dp[i][j] += max(dp[i-1][j],dp[i][j-1]);
                }
            }
            if (maxSum<dp[i][j]){
                maxSum = dp[i][j];
            }
        }
    }
    fout << maxSum << endl;
    return 0;
}
