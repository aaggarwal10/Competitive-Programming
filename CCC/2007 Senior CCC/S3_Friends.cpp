#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string.h>
using namespace std;
const int MAXN = 10001;
int friends[MAXN];
int visited[MAXN];
int N, friendA, friendB, A,B;
int nextCircle = 0;
map<pair<int,int>, int> cache;
map<pair<int,int>,int>::iterator it;
int distRec(int A, int B){
    if(cache.find(make_pair(A,B))!=cache.end()){
        return cache[make_pair(A,B)];
    }
    else{
        memset(visited,0,sizeof(visited));
        int curNode = A;
        int dist = 0;
        while(true){
            if(!visited[curNode]){
                cache[make_pair(A,friends[curNode])]=dist;
                visited[curNode] = 1;
                dist++;
                curNode = friends[curNode];
            }
            else{
                break;
            }
        }
        if(cache.find(make_pair(A,B))!=cache.end()){
            return cache[make_pair(A,B)];
        }
        else{
            cache[make_pair(A,B)] = -1;
            return -1;
        }
    }


}
int main()
{
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> friendA >> friendB;
        friends[friendA] = friendB;
        cache[make_pair(friendA,friendB)]=0;
    }
    while(1){
        cin >> A >> B;
        int distAB = distRec(A,B);
        if(A==0 && B==0){
            break;
        }
        if (distAB<0){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << " "<< distAB << endl;
        }
    }
    return 0;
}
