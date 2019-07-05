/*
ID: anish.51
PROB: butter
LANG: C++
*/
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>


using namespace std;

typedef pair<int,int> pi;

int shortestPath [810][810];//Pasture -> Pasture
int visitedPathLength[810] = {};
int graph[810][810] = {};//Path weights
vector<int> connectedVert[810];
int cowPositions[510] = {};
int numCows,numVerts, numPaths;
int const MAX_INF  = 1000000;
ifstream fin ("butter.in");
ofstream fout ("butter.out");

void FindShortPath(int pastureA){
    priority_queue<pi,vector<pi>,greater<pi>> bfs; //current pasture, and dist to the pasture

    for(int i = 1; i<=numVerts; i++){
        if(shortestPath[pastureA][i]!=MAX_INF){
            bfs.push(make_pair(shortestPath[pastureA][i],i));
        }
        visitedPathLength[i] = shortestPath[pastureA][i];
    }


    while(!bfs.empty()){
        int curLocation = bfs.top().second;
        int curLength = bfs.top().first;
        bfs.pop();
        for(int i = 0; i<connectedVert[curLocation].size(); i++){
            int newLocation = connectedVert[curLocation][i];
            if(graph[curLocation][newLocation]!=0 && visitedPathLength[newLocation]>curLength+graph[curLocation][newLocation]){
                visitedPathLength[newLocation]=curLength+graph[curLocation][newLocation];
                bfs.push(make_pair(curLength+graph[curLocation][newLocation],newLocation));
            }
        }

    }
    for(int i = 1; i<=numVerts; i++){
        shortestPath[pastureA][i] = shortestPath[i][pastureA] =  visitedPathLength[i];
    }
}

int main()
{
    fin >> numCows >> numVerts >> numPaths;
    //Set infinite path lengths
    for(int i = 0; i<810; i++){
        for(int j = 0; j<810; j++){
            if(i==j){
                shortestPath[i][j] = 0;
            }
            else{
                shortestPath[i][j] = shortestPath[j][i] = MAX_INF;
            }
        }
    }
    //Store Cow Start Positions
    for(int i = 0; i<numCows; i++){
        fin >> cowPositions[i];
    }
    //Make Graph
    for(int i = 0; i<numPaths; i++){
        int start, finish, length;
        fin >> start >> finish >> length;
        graph[start][finish] = graph[finish][start] = length;
        connectedVert[start].push_back(finish);
        connectedVert[finish].push_back(start);
    }

    for(int i = 1; i<numVerts+1; i++){
        FindShortPath(i);

    }

    int minTotDist = MAX_INF;
    for(int bellPasture = 1; bellPasture<=numVerts; bellPasture++){
        int totDist = 0;
        for(int cow = 0; cow<numCows; cow++){
            totDist+=shortestPath[cowPositions[cow]][bellPasture];
        }
        minTotDist = min(minTotDist,totDist);
    }
    fout << minTotDist << endl;
    return 0;
}
