#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

int N, M, R;
unsigned long r = 1;
int grid[301][301];
int cells = 0;
int X=0,Y=0;
vector<queue<int>> rotateGrid;
ifstream fin ("testcase7.in");
ofstream fout ("testcase7.out");
void reMake(int posX, int posY){
    int curX = posX;
    int curY = posY;
    int changeX = 1;
    int changeY = 0;

    queue<int> que = rotateGrid[posX];
    while (grid[curY][curX]==-1){
        if(curX==posX&&changeX==-1){
            changeX = 0;
            changeY =-1;
        }
        if(curX == M-posX-1&&changeX==1){
            changeX=0;
            changeY=1;
        }
        if(curY == posY && changeY==-1){
            changeY=0;
            changeX=1;
        }
        if(curY==N-posY-1 && changeY ==1){
            changeY = 0;
            changeX = -1;
        }
        grid[curY][curX] = que.front();
        que.pop();
        curX+=changeX;
        curY+= changeY;
        cells-=1;
    }

}
void makeGrid(int posX, int posY){
    queue<int> que;
    int curX = posX, curY = posY;
    int changeX = 1,changeY = 0;
    while(grid[curY][curX]!=-1){
        //cout << curY << " " << curX << endl;
        if(curX==posX&&changeX==-1){
            changeX = 0;
            changeY =-1;
        }
        if(curX == M-posX-1&&changeX==1){
            changeX=0;
            changeY=1;
        }
        if(curY == posY && changeY==-1){
            changeY=0;
            changeX=1;
        }
        if(curY==N-posY-1 && changeY ==1){
            changeY = 0;
            changeX = -1;
        }
        que.push(grid[curY][curX]);
        grid[curY][curX] = -1;
        curX+=changeX;
        curY+= changeY;
        cells+=1;
    }
    rotateGrid.push_back(que);
}
int main()
{
    fin >> N >> M >> R;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            fin >> grid[i][j];
        }
    }
    while (cells!=N*M){
        makeGrid(X,Y);
        X++;
        Y++;
    }
    for(int i=0 ; i<rotateGrid.size(); i++){
        for(int j = 0; j<R%rotateGrid[i].size(); j++){
            int first = rotateGrid[i].front();
            rotateGrid[i].pop();
            rotateGrid[i].push(first);
        }
    }
    X = 0;
    Y = 0;
    while (cells!=0){
        reMake(X,Y);
        X++;
        Y++;
    }
    for(int i = 0; i<N;i++){
        for(int j = 0; j<M; j++){
            fout << grid[i][j];
            if(j==M-1){
                fout << endl;
            }
            else{
                fout << " ";
            }
        }
    }
    return 0;
}
