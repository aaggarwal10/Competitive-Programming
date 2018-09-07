#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 10000;
int N;
map<int,vector<int>> connections;
int slidePaths [MAXN] = {};
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (1){
        int A,B;
        cin >> A >> B;
        if (A==0 && B==0){
            break;
        }
        connections[A].push_back(B);
    }
    slidePaths[1] = 1;
    for(int i = 1; i<N; i++){
        for(int endPoint: connections[i]){
            slidePaths[endPoint]+=slidePaths[i];
        }
    }

    cout << slidePaths[N] << endl;
    return 0;
}
