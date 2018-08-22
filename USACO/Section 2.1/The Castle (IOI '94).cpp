/*
IOI '94
ID: anish.51
LANG: C++
TASK: castle
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;
int N,M;
map<string,int> roomSizes;
map<string,int>::iterator it;
vector<vector<int>> dirs = {{0,1}, {1,0},{-1,0},{0,-1}};
void printMatrix(string *matrix, int r, int c)
{
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            cout<<matrix[i*c+j]<<" ";
        }
        cout<<endl;
    }
}
void printMatrix(int *matrix, int r, int c)
{
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            cout<<matrix[i*c+j]<<" ";
        }
        cout<<endl;
    }
}
void fillroom(string *matrix, int r, int c,int sx, int sy, int roomNum){
    vector<vector<int>> points = {{sx,sy}};
    int roomsize = 0;
    while(!points.empty()){
        vector<int> searchNode = points.back();
        points.pop_back();
        if (matrix[searchNode[1]*c +searchNode[0]] == "."){
            matrix [searchNode[1]*c + searchNode[0]] = to_string(roomNum);
            roomsize++;
            for (int i = 0; i<dirs.size(); i++){
                if(matrix[(searchNode[1]+dirs[i][1])*c+(searchNode[0]+dirs[i][0])]=="-" && matrix[(searchNode[1]+dirs[i][1]*2)*c+(searchNode[0]+dirs[i][0]*2)]=="."){
                    points.push_back({searchNode[0]+dirs[i][0]*2,searchNode[1]+dirs[i][1]*2});

                }
            }
        }
    }
    roomSizes[to_string(roomNum)]=roomsize;
}
int main()
{
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    fin >> N >> M;
    string grid [2*M+1][2*N+1];
    int wallPotential [2*M+1][2*N+1];
    for (int i = 0; i<2*M+1; i++){
        for (int j = 0; j<2*N+1; j++){
            grid[i][j] = "#";
            wallPotential[i][j] = 0;
        }
    }
    for (int i = 0; i<M; i++){
        for (int j = 0; j<N; j++){
            int room_type;
            fin >> room_type;
            if (room_type<8){
                grid[2*i+2][2*j+1]="-";
            }
            if(room_type%2!=1){
                grid[2*i+1][2*j] ="-";
            }
            if (room_type%4 != 2 && room_type%4  != 3){
                grid[2*i][2*j+1] = "-";
            }
            if (room_type%8 <= 3){
                grid[2*i+1][2*j+2] = "-";
            }

            grid[2*i+1][2*j+1] = ".";
        }
    }
    int roomnum = 0;
    for (int i = 0; i<2*M+1; i++){
        for (int j = 0; j <  2*N+1; j++){
            if (grid[i][j]=="."){
                fillroom((string*)grid,2*M+1,2*N+1,j,i,++roomnum);
            }
        }
    }

    for(int i = 1; i<2*M; i++){
        for(int j = 1; j<2*N; j++){
            int vertical = 0;
            int horizontal = 0;
            if (grid[i][j] == "#"){
                if (roomSizes.find(grid[i-1][j])!=roomSizes.end() && roomSizes.find(grid[i+1][j])!=roomSizes.end()&& grid[i-1][j]!=grid[i+1][j]){
                    vertical = roomSizes[grid[i-1][j]]+roomSizes[grid[i+1][j]];
                }
                if (roomSizes.find(grid[i][j-1])!=roomSizes.end() && roomSizes.find(grid[i][j+1])!=roomSizes.end() && grid[i][j-1]!=grid[i][j+1]){
                    horizontal = roomSizes[grid[i][j-1]]+roomSizes[grid[i][j+1]];
                }
                if (vertical >= horizontal){
                    grid[i][j] = "N";
                }
                else {
                    grid[i][j] = "E";
                }
                wallPotential[i][j] = max(vertical,horizontal);
            }
        }
    }
    int maxRoomSizeSmall = 0;
    for (it = roomSizes.begin(); it!=roomSizes.end();it++){
        if(maxRoomSizeSmall<(it->second)){
            maxRoomSizeSmall = it->second;
        }
    }
    int maxPotential = 0;
    int pos [2];

    for (int j = 0; j < 2*N+1;j++){
        for(int i = 2*M; i>=0; i--){
            if (wallPotential[i][j]>maxPotential){
                    maxPotential = wallPotential[i][j];
                    pos[0] = i;
                    pos[1] = j;
            }

        }
    }
    string direction = grid[pos[0]][pos[1]];
    int maxRoomSizeLarge = wallPotential[pos[0]][pos[1]];

    if (direction == "E"){
        pos[1]-=1;
    }
    else{
        pos[0]+=1;
    }
    pos[0] -= 1;
    pos[1] -= 1;
    pos[0] /= 2;
    pos[1] /= 2;
    pos[0] += 1;
    pos[1] += 1;
    fout << roomnum << endl;
    fout << maxRoomSizeSmall << endl;
    fout << maxRoomSizeLarge << endl;
    fout << pos[0] << " " << pos[1] << " " << direction << endl;
    return 0;
}


