#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int rows,cols;
    scanf("%d %d",&rows,&cols);
    char roboMap[rows][cols];
    for (int r = 0; r<rows;r++){
        for (int c = 0; c<cols;c++){
            scanf(" %c", &roboMap[r][c]);
        }
    }
    vector<vector<int>> points;
    int dists[rows][cols];
    int caught[rows][cols];
    for (int r = 0; r<rows;r++){
        for (int c = 0; c<cols;c++){
            dists[r][c]=999999;
            caught[r][c]=0;
            if (roboMap[r][c]=='S'){
                dists[r][c]=0;
                points.clear();
                vector<int> position = {r,c};
                points.push_back(position);
            }
        }
    }
    vector<int> dirs[4] = {{0,1},{1,0},{-1,0},{0,-1}};
    for (int r = 0; r<rows; r++){
        for (int c = 0; c<cols; c++){
            if (roboMap[r][c]=='C'){
                caught[r][c]=1;
                int change=0;
                for(int i=0; i<4; i++){
                    int xChange = dirs[i][0];
                    int yChange = dirs[i][1];
                    while (true){
                        if (roboMap[r+xChange*change][c+yChange*change]!='W'){
                            caught[r+xChange*change][c+yChange*change]=1;
                            change+=1;
                        }
                        else{
                            break;
                        }
                    }
                    change=0;
                }
            }
        }
    }
    while (!points.empty()){
        vector<int> point = points.back();
        int row = point[0];
        int col = point[1];
        points.pop_back();
        if ((roboMap[row][col]=='.'||roboMap[row][col]=='S') && caught[row][col]==0){
            for(int i=0; i<4; i++){
                int xDir = dirs[i][0];
                int yDir = dirs[i][1];
                if (dists[row][col] < dists[row + xDir][col + yDir] - 1){
                    dists[row + xDir][col + yDir] = dists[row][col] + 1;
                    vector<int> pos = {row + xDir, col + yDir};
                    points.push_back(pos);
                }
            }
        }
        else if (roboMap[row][col]=='R'){
            if (dists[row][col] < dists[row][col + 1]){
                dists[row][col + 1] = dists[row][col];
                vector<int> pos ={row, col+1};
                points.push_back(pos);
            }
        }
        else if (roboMap[row][col]=='L'){
            if (dists[row][col] < dists[row][col - 1]){
                dists[row][col - 1] = dists[row][col];
                vector<int> pos ={row, col-1};
                points.push_back(pos);
            }
        }
        else if (roboMap[row][col]=='U'){
            if (dists[row][col] < dists[row - 1][col]){
                dists[row - 1][col] = dists[row][col];
                vector<int> pos ={row - 1, col};
                points.push_back(pos);
            }
        }
        else if (roboMap[row][col]=='D'){
            if (dists[row][col] < dists[row + 1][col]){
                dists[row+1][col] = dists[row][col];
                vector<int> pos ={row + 1, col};
                points.push_back(pos);
            }
        }

    }
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            if (roboMap[i][j] == '.'){
                if (caught[i][j]==1 || dists[i][j]==999999){
                    cout<<-1<<endl;
                }
                else{
                    cout << dists[i][j] << endl;
                }
            }
        }
    }
    return 0;
}
