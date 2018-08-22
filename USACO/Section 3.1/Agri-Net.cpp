/*
ID: anish.51
PROB: agrinet
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int inTree[101]={0};
int distFromTree[101];
int adj[101][101];
int N;
const int INF = 1000000;
int totLength = 0;

bool allVisited(){
    for(int i = 0; i<N; i++){
        if (!inTree[i]){
            return false;
        }
    }
    return true;
}
void updateDist(){
    for(int i = 0; i<N; i++){
        if (inTree[i]){
            for(int j = 0; j<N; j++){
                if(distFromTree[j]>adj[i][j]){
                    distFromTree[j] = adj[i][j];
                }
            }
        }
    }
}
void prims(){
    inTree[0] = 1;
    while (!allVisited()){
        updateDist();
        int minDist = INF;
        int treeToAdd;
        for(int i = 0; i<N; i++){
            if(distFromTree[i]<minDist && !inTree[i]){
                minDist = distFromTree[i];
                treeToAdd = i;
            }
        }
        inTree[treeToAdd]=1;
        totLength+=minDist;
    }
}

int main()
{
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");
    fin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            int num;
            fin >>  num;
            adj[i][j] = num;
        }
    }
    for(int i = 0; i<101; i++){
        distFromTree[i] = INF;
    }
    prims();
    fout<<totLength<<endl;
    return 0;
}
