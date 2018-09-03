#include <iostream>
#include <queue>
using namespace std;
int testcases, N, M;
int const MAX_INT = 21;
int visited[MAX_INT][MAX_INT];
char grid[MAX_INT][MAX_INT];
int dist[MAX_INT][MAX_INT];
int directions[4][2];

void solveGrid(){
    queue<pair<int,int>> que;
    dist[0][0] = 1;
    que.push(make_pair(0,0));
    while(!que.empty()){
        if (dist[N-1][M-1]!=MAX_INT*MAX_INT){
            break;
        }
        pair<int,int> pos = que.front();
        que.pop();
        if (grid[pos.first][pos.second]=='+'){
            for(int i = 0; i<4; i++){
                if(0<=pos.first+directions[i][0] && pos.first+directions[i][0]<N && 0<=pos.second+directions[i][1] && pos.second+directions[i][1]<M){
                    if(!visited[pos.first+directions[i][0]][pos.second+directions[i][1]] && dist[pos.first+directions[i][0]][pos.second+directions[i][1]]>dist[pos.first][pos.second]+1){
                        visited[pos.first+directions[i][0]][pos.second+directions[i][1]] = 1;
                        dist[pos.first+directions[i][0]][pos.second+directions[i][1]]=dist[pos.first][pos.second]+1;
                        que.push(make_pair(pos.first+directions[i][0],pos.second+directions[i][1]));
                    }
                }
            }
        }
        else if(grid[pos.first][pos.second]=='-'){
            for(int i = 2; i<4; i++){
                if(0<=pos.first+directions[i][0] && pos.first+directions[i][0]<N && 0<=pos.second+directions[i][1] && pos.second+directions[i][1]<M){
                    if(!visited[pos.first+directions[i][0]][pos.second+directions[i][1]] && dist[pos.first+directions[i][0]][pos.second+directions[i][1]]>dist[pos.first][pos.second]+1){
                        visited[pos.first+directions[i][0]][pos.second+directions[i][1]] = 1;
                        dist[pos.first+directions[i][0]][pos.second+directions[i][1]]=dist[pos.first][pos.second]+1;
                        que.push(make_pair(pos.first+directions[i][0],pos.second+directions[i][1]));
                    }
                }
            }
        }
        else if(grid[pos.first][pos.second]=='|'){
            for(int i = 0; i<2; i++){
                if(0<=pos.first+directions[i][0] && pos.first+directions[i][0]<N && 0<=pos.second+directions[i][1] && pos.second+directions[i][1]<M){
                    if(!visited[pos.first+directions[i][0]][pos.second+directions[i][1]] && dist[pos.first+directions[i][0]][pos.second+directions[i][1]]>dist[pos.first][pos.second]+1){
                        visited[pos.first+directions[i][0]][pos.second+directions[i][1]] = 1;
                        dist[pos.first+directions[i][0]][pos.second+directions[i][1]]=dist[pos.first][pos.second]+1;
                        que.push(make_pair(pos.first+directions[i][0],pos.second+directions[i][1]));
                    }
                }
            }
        }
    }
}
int main()
{
    //set directions
    directions[0][0] = 1;
    directions[0][1] = 0;
    directions[1][0] = -1;
    directions[1][1] = 0;
    directions[2][0] = 0;
    directions[2][1] = 1;
    directions[3][0] = 0;
    directions[3][1] = -1;
    cin >> testcases;
    while(testcases){
        cin >> N >> M;
        for(int i = 0; i<N; i++){
            for (int j = 0; j<M; j++){
                cin >> grid[i][j];
                visited[i][j] = 0;
                if(grid[i][j] == '*'){
                    dist[i][j] = -1;
                }
                else{
                    dist[i][j] = MAX_INT*MAX_INT;
                }
            }
        }
        solveGrid();
        if(dist[N-1][M-1]==MAX_INT*MAX_INT || dist[N-1][M-1]==-1){
            cout<<-1<<endl;
        }
        else{
            cout << dist[N-1][M-1] << endl;
        }
        testcases--;
    }
    return 0;
}
