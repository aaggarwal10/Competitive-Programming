/*
ID: anish.51
PROB: fence
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int graph[510][510] = {};
vector<int> soln;
int deg[510] = {};
int numFences, startNode = 510;
ifstream fin ("fence.in");
ofstream fout ("fence.out");


int main()
{
    fin >> numFences;
    for(int i = 0; i<numFences;i++){
        int start, finish;
        fin >> start >> finish;
        graph[start][finish]+=1;
        graph[finish][start] += 1;
        deg[start]+=1;
        deg[finish]+=1;
    }

    for(int i = 1; i<510; i++){
        if(deg[i]%2 == 1){
            startNode = i;
            break;
        }
        else if (deg[i]!=0){
            startNode = min(startNode,i);
        }
    }

    vector<int> nodeStack;
    vector<int> path;
    int curNode = startNode;
    while (!nodeStack.empty() || deg[curNode]!=0){
        if(deg[curNode]==0){
            path.push_back(curNode);
            curNode = nodeStack.back();
            nodeStack.pop_back();
        }
        else{
            for(int i = 0; i<510; i++){
                if(graph[curNode][i]>0){
                    nodeStack.push_back(curNode);
                    graph[curNode][i] -=1;
                    graph[i][curNode] -=1;

                    deg[i] -=1;
                    deg[curNode]-=1;
                    curNode = i;
                    break;
                }
            }
        }
    }
    fout << startNode << endl;
    while(!path.empty()){
        fout << path.back() << endl;
        path.pop_back();
    }
    return 0;
}
