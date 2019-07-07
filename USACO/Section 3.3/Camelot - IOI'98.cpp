/*
ID: anish.51
PROB: camelot
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

int knightGraph [32][32][32][32][2];
int kingGraph[32][32];
int extraMoves[32][32];
pi knightPU[32][32];

int kingSX, kingSY, rows, cols;
vector<pi> knightPos;
vector<pi> knightDir;
ifstream fin ("camelot.in");
ofstream fout ("camelot.out");

void bfs(int sx, int sy){
    queue<pi> bfsQue;

    bfsQue.push(make_pair(sx,sy));
    while(!bfsQue.empty()){
        int curX = bfsQue.front().first;
        int curY = bfsQue.front().second;
        bfsQue.pop();
        for(pi dir: knightDir){
            int dx = dir.first;
            int dy = dir.second;
            if(curX+dx<=cols && curX+dx >=1 && curY+dy<=rows && curY+dy>=1){
                if(knightGraph[sx][sy][curX+dx][curY+dy][0]>knightGraph[sx][sy][curX][curY][0]+1){
                    knightGraph[sx][sy][curX+dx][curY+dy][0] = knightGraph[sx][sy][curX][curY][0]+1;
                    bfsQue.push(make_pair(curX+dx,curY+dy));
                }
            }
        }
    }
}
void bfsKnight(pi kPos, int sx, int sy){
    queue<pi> bfsQueue;
    int visited[32][32] = {};
    bfsQueue.push(make_pair(sx,sy));
    visited[sx][sy] = 1;
    while(!bfsQueue.empty()){
        int curX = bfsQueue.front().first;
        int curY = bfsQueue.front().second;
        bfsQueue.pop();
        for(pi dir: knightDir){
            int dx = dir.first;
            int dy = dir.second;
            if(curX+dx<=cols && curX+dx >=1 && curY+dy<=rows && curY+dy>=1){
                if(knightGraph[kPos.first][kPos.second][curX+dx][curY+dy][1]>knightGraph[kPos.first][kPos.second][curX][curY][1]+1){
                   knightGraph[kPos.first][kPos.second][curX+dx][curY+dy][1]=knightGraph[kPos.first][kPos.second][curX][curY][1]+1;
                   bfsQueue.push(make_pair(curX+dx,curY+dy));

                }

            }
        }
    }
}
void printKG(int x, int y){
    for(int i = 0; i<32; i++){
        for(int j = 0; j<32; j++){
            cout << knightGraph[x][y][i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    fin >> rows >> cols;
    char kSX;
    fin >> kSX >> kingSY;
    kingSX = kSX;
    kingSX -= 64;
    int knightPosY;
    char knightPosX;

    while (fin >> knightPosX >> knightPosY){
        knightPos.push_back(make_pair(int(knightPosX)-64,knightPosY));
    }

    knightDir.push_back(make_pair(1,2));
    knightDir.push_back(make_pair(2,1));
    knightDir.push_back(make_pair(-1,2));
    knightDir.push_back(make_pair(2,-1));
    knightDir.push_back(make_pair(1,-2));
    knightDir.push_back(make_pair(-2,1));
    knightDir.push_back(make_pair(-1,-2));
    knightDir.push_back(make_pair(-2,-1));

    memset(knightGraph, 1, sizeof(knightGraph));
    memset(kingGraph,1,sizeof(kingGraph));
    memset(extraMoves,1,sizeof(extraMoves));
    for(int i = 1; i<=cols; i++){
        for(int j = 1; j<=rows; j++){
            knightGraph[i][j][i][j][0] = 0;
            bfs(i,j);

        }
    }

    for(int endX = 1; endX<=cols; endX++){
        for(int endY = 1; endY<=rows; endY++){
            kingGraph[endX][endY] = max(abs(endX-kingSX),abs(endY-kingSY));
            for(pi kPos : knightPos){
                knightGraph[kPos.first][kPos.second][endX][endY][1] = kingGraph[endX][endY] + knightGraph[kPos.first][kPos.second][endX][endY][0];
            }
        }
    }

    for(pi kPos : knightPos){
        int sx = 1<<20,sy=1<<20;
        int mini = 1<<20;
        for(int endX = 1; endX<=cols; endX++){
            for(int endY=1; endY<=rows; endY++){
                if(mini>knightGraph[kPos.first][kPos.second][endX][endY][1]){
                    mini = knightGraph[kPos.first][kPos.second][endX][endY][1];
                    sx = endX;
                    sy = endY;
                }
            }
        }
        bfsKnight(kPos,sx,sy);
    }
    for(int endX = 1; endX<=cols; endX++){
        for(int endY = 1; endY<=rows; endY++){
            for(pi kPos : knightPos){
                if(extraMoves[endX][endY]>knightGraph[kPos.first][kPos.second][endX][endY][1] - knightGraph[kPos.first][kPos.second][endX][endY][0]){
                    extraMoves[endX][endY] = knightGraph[kPos.first][kPos.second][endX][endY][1] - knightGraph[kPos.first][kPos.second][endX][endY][0];
                }
            }
        }
    }
    int minDist = 1<<20;
    for(int endX = 1; endX<=cols; endX++){
        for(int endY = 1; endY<=rows; endY++){
            int knightDistToEnd = 0;
            for(pi kPos: knightPos){
                knightDistToEnd+=knightGraph[kPos.first][kPos.second][endX][endY][0];

            }
            minDist = min(knightDistToEnd+extraMoves[endX][endY],minDist);
        }
    }

    if(knightPos.size()==0){
        fout << 0 << endl;
        return 0;
    }
    fout<< minDist << endl;
    return 0;
}
