/*
ID: anish.51
PROB: cowtour
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int adj[151][151];
vector<vector<int>> positions;
vector<vector<int>> pastures;
vector<int> visited;
int N;
float dist[152];
int visit[152];
float diameter = 1000000;

bool nodeConnected(vector<int> tree, int node){
    for(int i = 0; i<tree.size(); i++){
        if (tree[i] == node){
            return true;
        }
    }
    return false;
}
bool allVisited(){
    bool allChecked = true;
    for(int i = 0; i<N; i++){
        if (!visited[i]){
            allChecked = false;
            break;
        }
    }
    return allChecked;
}
int findFirst(){
    int searchNode = -1;
    for(int i = 0; i<N; i++){
        if(!visited[i]){
            searchNode=i;
            break;
        }
    }
    return searchNode;
}
void findPastures(){
    while (!allVisited()){
        int searchNode = findFirst();
        queue<int> nodes;
        nodes.push(searchNode);
        vector<int> connectedPasture = {searchNode};
        while(!nodes.empty()){
            searchNode = nodes.front();
            visited[searchNode] = 1;
            nodes.pop();
            for(int i = 0; i<N; i++){
                if (adj[searchNode][i] && !nodeConnected(connectedPasture,i)){
                    nodes.push(i);
                    connectedPasture.push_back(i);
                }
            }
        }
        pastures.push_back(connectedPasture);
    }
}
double findDistance(int nodeA, int nodeB){
    float diffA = positions[nodeA][0] - positions[nodeB][0];
    float diffB = positions[nodeA][1] - positions[nodeB][1];
    return sqrt(diffA*diffA+diffB*diffB);
}
void djikstra(int startNode, vector<int> graph){
    dist[startNode] = 0;
    queue<int> que;
    que.push(startNode);
    while(!que.empty()){
        int node = que.front();
        que.pop();
        visit[node] = 1;
        for(int i = 0; i<graph.size(); i++){
            if (adj[graph[node]][graph[i]]&&!visit[i]){
                if(dist[i]>dist[node]+findDistance(graph[i],graph[node])){
                    dist[i]=dist[node]+findDistance(graph[node],graph[i]);
                    que.push(i);
                }
            }
        }
    }
}
void findDiam(vector<int> graph){
    for(int i = 0; i<graph.size(); i++){
        dist[i] = 10000000;
        visit[i] = 0;
    }
    djikstra(0,graph);
    float maxDist = 0;
    int index;
    for(int i = 0; i<graph.size(); i++){
        if (dist[i]>maxDist){
            maxDist = dist[i];
            index = i;
        }
        dist[i] = 10000000;
        visit[i] = 0;
    }
    djikstra(index,graph);
    maxDist = 0;
    for(int i = 0; i<graph.size();i++){
        if(dist[i]>maxDist){
            maxDist = dist[i];
        }
    }
    if (maxDist<diameter){
        diameter = maxDist;
    }

}
void connect2Pastures(){
    for(int i = 1; i<pastures.size(); i++){
        for(int j = 0; j<i; j++){
            for(int a = 0; a<pastures[i].size(); a++){
                for(int b = 0; b<pastures[j].size(); b++){
                    adj[pastures[i][a]][pastures[j][b]] = 1;
                    adj[pastures[j][b]][pastures[i][a]] = 1;
                    vector<int> joinedPastures = pastures[i];
                    joinedPastures.insert(joinedPastures.end(),pastures[j].begin(),pastures[j].end());
                    findDiam(joinedPastures);
                    adj[pastures[i][a]][pastures[j][b]] = 0;
                    adj[pastures[j][b]][pastures[i][a]] = 0;
                }
            }
        }
    }
}
int main()
{
    ifstream fin ("cowtour.in");
    ofstream fout ("cowtour.out");
    fin >> N;
    for(int i = 0; i<N; i++){
        visited.push_back(0);
        int posX,posY;
        fin >> posX >> posY;
        positions.push_back({posX,posY});
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            char c;
            fin >> c;
            adj[i][j] = c;
            adj[i][j]-=48;
        }
    }
    findPastures();
    connect2Pastures();
    fout << fixed;
    fout << setprecision(6);
    fout << diameter <<endl;

    return 0;
}
