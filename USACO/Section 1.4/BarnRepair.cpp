/*
ID: anish.51
PROB: barn1
LANG: C++
*/
#include<bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> cowAdjacency;
vector<int> inputVector;
int M,S,C;
int a;

int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    fin >> M >> S >> C;
    if (M>=C){
        for (int i = 0; i < C ; i++){
            fin >> a;
        }
        fout << C << endl;
    }
    else{
        for (int i = 0; i<C; i++){
            fin >> a;
            inputVector.push_back(a);
        }
        sort(inputVector.begin(),inputVector.end());
        for (int i = 0; i<C; i++){
            a = inputVector[i];
            if (cowAdjacency.size() == 0){
                vector<int> newVec = {a};
                cowAdjacency.push_back(newVec);
            }
            else{
                for (int n = 0; n<cowAdjacency.size();n++){
                    for(int m = 0; m<cowAdjacency[n].size();m++){
                        if (cowAdjacency[n][m]-1 == a || cowAdjacency[n][m]+1 == a ){
                            cowAdjacency[n].push_back(a);
                            a = -1;
                        }
                    }
                }
                if(a!=-1){
                    vector<int> newVec = {a};
                    cowAdjacency.push_back(newVec);
                }
            }
        }
        for (int n = 0; n<cowAdjacency.size();n++){
            sort(cowAdjacency.begin(),cowAdjacency.end());
            for(int m = 0; m<cowAdjacency[n].size();m++){
                sort(cowAdjacency[n].begin(),cowAdjacency[n].end());
            }
        }
        while(cowAdjacency.size()!=M){
            vector<int> diffs = {};
            for (int i = 1; i<cowAdjacency.size(); i++){
                diffs.push_back(cowAdjacency[i][0]-cowAdjacency[i-1].back());
            }
            int minimum = 300;
            int index = -1;
            for (int i = 0; i<diffs.size(); i++){
                if (minimum > diffs[i]){
                    minimum = diffs[i];
                    index = i;
                }
            }

            vector<int> joined;
            joined.reserve(cowAdjacency[index].size() + cowAdjacency[index+1].size());
            joined.insert(joined.end(),cowAdjacency[index].begin(),cowAdjacency[index].end());
            joined.insert(joined.end(),cowAdjacency[index+1].begin(),cowAdjacency[index+1].end());
            cowAdjacency[index] = joined;
            cowAdjacency.erase(cowAdjacency.begin()+index+1);

        }
        int totBoardSize = 0;
        for (int i = 0; i<cowAdjacency.size();i++){
            totBoardSize += (cowAdjacency[i].back() - cowAdjacency[i][0])+1;
        }

        fout << totBoardSize << endl;
    }
    return 0;
}
