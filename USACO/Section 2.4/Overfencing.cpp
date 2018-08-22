/*
ID: anish.51
PROB: maze1
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <deque>
using namespace std;

int H,W;
vector<vector<int>> startPos;
string grid[2*101+1][2*39+1];
int steps[2*101+1][2*39+1];
vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
int maxDist=0;

bool check(vector<int> position){
    if (0 <= position[0] && position[0] < 2*H+1 && 0 <= position[1] && position[1] < 2*W+1){
        return true;
    }
    return false;
}
void bfsRooms(){
    deque<vector<int>> que = {startPos[0],startPos[1]};
    while (!que.empty()){
        vector<int> posToCheck = que.front();
        que.pop_front();
        for(int dir=0; dir<4; dir++){
            vector<int> newPlace = {posToCheck[0]+directions[dir][0],posToCheck[1]+directions[dir][1]};
            if(check(newPlace)){
                if(steps[posToCheck[0]][posToCheck[1]]+1<steps[newPlace[0]][newPlace[1]]){
                    steps[newPlace[0]][newPlace[1]]=steps[posToCheck[0]][posToCheck[1]] + 1;
                    que.push_back(newPlace);
                }
            }
        }
    }
}

void findMax(){
    for(int i = 0; i<2*H+1;i++){
        for(int j = 0; j<2*W+1; j++){
            if (steps[i][j]>maxDist){
                maxDist=steps[i][j];
            }
        }
    }
}
int main()
{
    ifstream fin ("maze1.in");
    ofstream fout ("maze1.out");
    fin >> W >> H;
    fin.ignore();
    for(int i = 0; i<H*2+1; i++){
        string line;
        getline(fin,line);
        for(int j = 0; j<line.length(); j++){
            grid[i][j] = line[j];
            if (line[j] == ' '  && (j==line.length()-1 || j==0 || i == 0 || i == H*2)){
                steps[i][j] = 0;
                startPos.push_back({i,j});
            }
            else if (line[j]==' '){
                steps[i][j]=1000000;
            }
            else{
                steps[i][j] = -1;
            }
        }
    }
    bfsRooms();
    findMax();
    fout<<(maxDist+1)/2 << endl;
    return 0;
}
