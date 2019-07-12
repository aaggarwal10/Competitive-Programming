/*
ID: anish.51
LANG: C++
TASK: nuggets
*/
#include <bits/stdc++.h>

using namespace std;

int dp[120000] = {};
vector<int> packages;
int N;
int main()
{
#ifndef LOCAL
    ifstream cin("nuggets.in");
    ofstream cout("nuggets.out");
#endif
    cin >> N;
    for(int i = 0; i<N; i++){
        int x;
        cin >> x;
        packages.push_back(x);
        dp[x] = 1;
    }
    for(int i = 0; i<120000; i++){
        for(int j : packages){
            if(i-j>=0 && dp[i-j] == 1){
                dp[i] = 1;
                break;
            }
        }
    }
    for(int i = 120000-1; i>=0; i-=1){
        if(dp[i] == 0 && i>65356){
            cout << 0 << endl;
            return 0;
        }
        if(dp[i] == 0){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
