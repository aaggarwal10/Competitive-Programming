/*
ID: anish.51
PROB: fence6
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;

int graph[100][100]={};
int weights[110] = {};
int N;
int curVert = 0;
int minP = 1<<20;
unordered_map<int, pi> edgesConn;
unordered_map<int, vector<int>> vertConn;
int bfs(int nodeA, int nodeB){
    int visited[110];
    memset(visited,1,sizeof(visited));
    queue<pi> bfs;
    bfs.push(make_pair(nodeA,0));
    visited[nodeA] = 0;
    while(!bfs.empty()){
        int curN = bfs.front().first;
        int dist = bfs.front().second;
        bfs.pop();
        for(int i = 0; i<curVert; i++){
            if(visited[i]>dist+graph[i][curN]&&graph[i][curN]!=0){
                visited[i]=dist+graph[i][curN];
                bfs.push(make_pair(i,dist+graph[i][curN]));
            }
        }
    }
    return visited[nodeB];
}
void ConnectE(int edge, int vertex){

    if(edgesConn.find(edge)==edgesConn.end()){
        edgesConn[edge]=make_pair(vertex,-1);
    }
    else if (edgesConn[edge].second==-1){
        edgesConn[edge].second = vertex;
    }
}
bool Completed(int edge){
    if(edgesConn.find(edge)!=edgesConn.end()&&edgesConn[edge].second!=-1){
        return true;
    }
    return false;
}
bool Share(pi edgeA, pi edgeB){
    if((edgeA.first==edgeB.first && edgeA.first!=-1)){
        return true;
    }
    else if((edgeA.first==edgeB.second && edgeA.first!=-1)){
        return true;
    }
    else if((edgeA.second==edgeB.first && edgeB.first!=-1)){
        return true;
    }
    else if((edgeA.second==edgeB.second && edgeA.second!=-1)){
        return true;
    }
    else{
        return false;
    }
}
bool Share(int edgeA, int edgeB){
    if(edgesConn.find(edgeA)!=edgesConn.end()&&edgesConn.find(edgeB)!=edgesConn.end() && Share(edgesConn[edgeA],edgesConn[edgeB])){
        return true;
    }
    return false;
}
void getMin(){
    for(int startN = 0; startN<curVert; startN++){
        for(int endN=0; endN<startN; endN++){
            if(graph[startN][endN]!=0){
                int tmp = graph[startN][endN];
                graph[startN][endN] = graph[endN][startN] = 0;
                int tmp2 = bfs(endN,startN);
                minP = min(tmp+tmp2,minP);
                graph[startN][endN] = graph[endN][startN] = tmp;

            }
        }
    }

}
int main()
{
#ifndef LOCAL
    ifstream cin("fence6.in");
    ofstream cout("fence6.out");
#endif
    cin >> N;

    for(int j = 0; j<N; j++){
        int curE, wei, connA, connB;
        cin >> curE >> wei >> connA >> connB;
        weights[curE] = wei;

        int connectedE;
        for(int i = 0 ; i<connA; i++){
            cin >> connectedE;
            if(!Share(connectedE,curE))
                ConnectE(connectedE, curVert);
        }
        if(!Share(connectedE,curE)){
            ConnectE(curE,curVert);
            curVert+=1;
        }
        for(int i = 0 ; i<connB; i++){
            cin >> connectedE;
            if(!Share(connectedE,curE))
                ConnectE(connectedE, curVert);
        }
        if(!Share(connectedE,curE)){
            ConnectE(curE,curVert);
            curVert+=1;
        }
    }
    for(int i = 1; i<=N; i++){
        graph[edgesConn[i].first][edgesConn[i].second] = graph[edgesConn[i].second][edgesConn[i].first] = weights[i];
    }

    getMin();
    cout << minP << endl;
    return 0;
}
