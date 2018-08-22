/*
ID: anish.51
LANG: C++
TASK: milk3
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
vector<vector<int>> graph;
vector<int> capacity;
vector<vector<int>> nodesToSearch;
bool isVisited(vector <int> n){
    bool found = false;
    for (int i = 0; i<graph.size();i++){
        if (n == graph[i]){
            found = true;
        }
    }
    return found;
}
int pourBFS(){
    while (!nodesToSearch.empty()){
        vector<int> node = nodesToSearch.back();
        nodesToSearch.pop_back();
        if (!isVisited(node)){
            graph.push_back(node);
            //Pour into A
            if (node[0] < capacity[0]){
                //from B
                vector <int> newNode = {node[0]+min(node[1],capacity[0]-node[0]),max(0,node[1] - (capacity[0] - node[0])),node[2]};
                if (!isVisited(newNode)){
                    nodesToSearch.push_back(newNode);
                }
                //from C
                newNode = {node[0]+min(node[2],capacity[0]-node[0]) ,node[1], max(0,node[2]-(capacity[0]-node[0]))};
                if (!isVisited(newNode)){
                    nodesToSearch.push_back(newNode);
                }
            }
            //Pour into B
            if (node[1]<capacity[1]){
                //from A
                vector <int> newNode = {max(0,node[0] - (capacity[1]-node[1])),node[1]+min(node[0], capacity[1] - node[1]),node[2]};
                if (!isVisited(newNode)){
                    nodesToSearch.push_back(newNode);
                }
                //from C
                newNode = {node[0] ,node[1]+min(node[2],capacity[1]-node[1]),max(0,node[2]-(capacity[1]-node[1]))};
                if (!isVisited(newNode)){
                    nodesToSearch.push_back(newNode);
                }
            }
            //Pour into C
            if (node[2]<capacity[2]){
                //from A
                vector <int> newNode = {max(0,node[0] - (capacity[2]-node[2])),node[1],node[2]+min(node[0], capacity[2] - node[2])};
                if (!isVisited(newNode)){
                    nodesToSearch.push_back(newNode);
                }
                //from B
                newNode = {node[0] ,max(0,node[1]-(capacity[2]-node[2])),node[2]+min(node[1], capacity[2] - node[2])};
                if (!isVisited(newNode)){
                    nodesToSearch.push_back(newNode);
                }
            }
        }

    }
}
int main()
{
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    int A,B,C;
    fin >> A >> B >> C;
    capacity = {A,B,C};
    vector<int> c = {0,0,C};
    nodesToSearch.push_back(c);
    pourBFS();
    vector<int> answer;
    while (!graph.empty()){
        vector<int> vertex = graph.back();
        graph.pop_back();
        if (vertex[0] == 0){
            answer.push_back(vertex[2]);
        }
    }
    sort(answer.begin(),answer.end());
    for (int i = 0; i < answer.size()-1; i++){
        fout << answer[i] << " ";
    }
    fout << answer[answer.size()-1] << "\n";
    return 0;
}
