#include <bits/stdc++.h>
/*
ID: anish.51
PROB: game1
LANG: C++
*/
using namespace std;

int arr[110],N,tot;
int mem[110][110];
int maximumPoints(int lowBound, int maxBound){
    if(lowBound==maxBound){
        return arr[lowBound];
    }
    else if(lowBound>maxBound){
        return 0;
    }
    else if(mem[lowBound][maxBound]==-1){
         mem[lowBound][maxBound] = max(min(maximumPoints(lowBound+2,maxBound),maximumPoints(lowBound+1,maxBound-1))+arr[lowBound],min(maximumPoints(lowBound+1,maxBound-1),maximumPoints(lowBound,maxBound-2))+arr[maxBound]);
    }
    return mem[lowBound][maxBound];
}
int main()
{
#ifndef LOCAL
    ifstream cin("game1.in");
    ofstream cout("game1.out");
#endif
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            mem[i][j] = -1;
        }
    }
    for(int i = 0; i<N; i++){
        cin >> arr[i];
        tot+=arr[i];
    }
    int p1 = maximumPoints(0,N-1);
    cout << p1 << " " << tot-p1 <<endl;
    return 0;
}
