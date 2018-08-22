/*
ID: anish.51
PROB: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int dists[60][60]={0};
int distanceToZ[60]={0};
int N;

void bfs(){
    int node = 25;
    queue<int> que;
    que.push(node);
    while(!que.empty()){
        int searchNode = que.front();
        que.pop();
        for(int i = 0; i<60 ; i++){
            if (dists[searchNode][i]){
                if(distanceToZ[i]>dists[searchNode][i]+distanceToZ[searchNode]){
                    distanceToZ[i] = dists[searchNode][i] +distanceToZ[searchNode];
                    que.push(i);
                }
            }
        }
    }
}
int main()
{
    ifstream fin ("comehome.in");
    ofstream fout ("comehome.out");
    fin >> N;
    for(int i = 0; i<60; i++){
        distanceToZ[i] = 1000000;
        for(int j = 0; j<60; j++){
            dists[i][j] = 1000000;

        }
    }
    for(int i = 0; i<N; i++){
        char start,finish;
        int distance;
        fin >> start >> finish >> distance;
        int s = start,f = finish;
        s -= 65;
        f -= 65;

        dists[s][f] = dists[f][s] = min(dists[f][s],distance);

    }

    distanceToZ[25]=0;
    bfs();
    int minDist = 100000000;
    int chara = 0;
    for(int i = 0; i<25; i++){
        if (distanceToZ[i]<minDist){
            minDist = distanceToZ[i];
            chara = i;
        }
    }
    fout << static_cast<char>(chara+65) << " " << minDist << endl;
    return 0;
}

