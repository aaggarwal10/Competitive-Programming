#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> possAnswers;
vector<vector<int>> grid;
vector<vector<int>> testingGrid;
int counter = 0;
int N,M;
void makeAnswers(int n){
    vector<vector<int>> que;
    que.push_back({});
    while(!que.empty()){
        vector<int> lastt = que.back();
        que.pop_back();
        if(lastt.size()<n){
            lastt.push_back(1);
            que.push_back(lastt);
            lastt.pop_back();
            lastt.push_back(0);
            que.push_back(lastt);
        }
        else{
            possAnswers.push_back(lastt);
        }
    }
}
bool checkForAns(vector<int> possLastRow){
    testingGrid = grid;
    int curIndex = testingGrid.size()-1;
    while (1){
        if (curIndex>=0){
            if(testingGrid[curIndex]==possLastRow){
                return true;
            }
            else{
                for(int i = 0; i<testingGrid[curIndex].size(); i++){
                    possLastRow[i] = (possLastRow[i]+testingGrid[curIndex][i])%2;
                }
                curIndex--;

            }
        }
        else{
            return false;
        }
    }
}
int main()
{
    cin>>N>>M;
    makeAnswers(M);
    for(int i = 0; i<N; i++){
        vector<int> row;
        for(int j = 0; j<M; j++){
            int a;
            cin >> a;
            row.push_back(a);
        }
        grid.push_back(row);
    }
    for(int i = 0; i<possAnswers.size(); i++){
        if (checkForAns(possAnswers[i])){
            counter+=1;
        }
    }
    cout << counter << endl;
    return 0;
}
