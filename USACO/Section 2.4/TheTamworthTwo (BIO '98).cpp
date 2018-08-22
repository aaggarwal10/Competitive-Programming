/*
ID: anish.51
PROB: ttwo
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

string grid[10][10];
vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
vector<int> cowPos, johnPos;
int cowDir=0, johnDir=0, minutes = 0;

bool check(vector<int> position){
    if (0<=position[0] && position[0] < 10 && position[1] < 10 && position[1] >=0){
        if(grid[position[0]][position[1]]!="*"){
            return true;
        }
    }
    return false;
}
void movePlayers(){
    while (!(cowPos==johnPos)&&minutes<1000000){
        minutes+=1;
        //move john
        vector<int> newPos = {johnPos[0]+directions[johnDir][0],johnPos[1]+directions[johnDir][1]};
        if(check(newPos)){
            johnPos=newPos;
        }
        else{
            johnDir = (johnDir+1)%4;
        }
        //move cows
        newPos = {cowPos[0]+directions[cowDir][0],cowPos[1]+directions[cowDir][1]};
        if(check(newPos)){
            cowPos = newPos;
        }
        else{
            cowDir = (cowDir+1)%4;
        }
    }
}
int main()
{
    ifstream fin ("ttwo.in");
    ofstream fout ("ttwo.out");
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            char cell;
            fin >> cell;
            grid[i][j] = cell;
            if (cell == 'F'){
                johnPos = {i,j};
            }
            if (cell == 'C'){
                cowPos = {i,j};
            }
        }
    }
    movePlayers();
    if (minutes==1000000){
        fout << 0 << endl;
    }
    else{
        fout << minutes << endl;
    }
    return 0;
}
