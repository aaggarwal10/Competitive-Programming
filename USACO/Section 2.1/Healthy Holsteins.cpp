/*
ID: anish.51
LANG: C++
TASK: holstein
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;
int V,G;
vector<int> vitaminReq;
vector<vector<int>> feed;
vector<vector<int>> choice;
vector<vector<int>> combinations;
map<int,vector<vector<int>>> sortedChoices;
map<int,vector<vector<int>>>::iterator it;
int scoops = 20;
void addChoice(vector<int> cur, int c){
    if (cur.size() == c){
        int numchoice = count(cur.begin(),cur.end(),1);
        if (sortedChoices.find(numchoice) == sortedChoices.end()){
            vector<vector<int>> placeholder;
            placeholder.push_back(cur);
            sortedChoices[numchoice] = placeholder;
        }
        else{
            sortedChoices[numchoice].push_back(cur);
        }
    }
    else{
        cur.push_back(0);
        addChoice (cur,c);
        cur.pop_back();
        cur.push_back(1);
        addChoice (cur,c);
    }
}
void sortChoice(){
    for(it = sortedChoices.begin(); it!=sortedChoices.end();it++){
        for(int i = 0; i<(it->second).size() ; i++){
            choice.push_back(it->second[i]);
        }
    }
}
int main()
{
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    fin >> V;
    for(int i = 0; i<V; i++){
        int curfeed;
        fin >> curfeed;
        vitaminReq.push_back(curfeed);
    }
    fin >> G;
    vector<int> start;
    start.clear();
    addChoice(start, G);
    sortChoice();
    for(int i = 0; i<G; i++){
        vector <int> cowfeed;
        for(int j = 0; j<V; j++){
            int amount;
            fin >> amount;
            cowfeed.push_back(amount);
        }
        feed.push_back(cowfeed);
    }
    for(int i = 0; i<choice.size();i++){
        vector<int> startingcomb;
        for(int j = 0; j<V; j++){
            startingcomb.push_back(0);
        }
        combinations.push_back(startingcomb);
    }
    for(int i = 0; i<choice.size(); i++){
        for(int j = 0; j<choice[i].size();j++){
            if (choice[i][j]==1){
                for(int k = 0; k<V; k++)
                    combinations[i][k]+=feed[j][k];
            }
        }
    }
    vector<int> posScoops;
    for(int i = 0; i<combinations.size(); i++){
        if(count(choice[i].begin(),choice[i].end(),1) > scoops){
            break;
        }
        else{
            bool works = true;
            for(int j = 0; j<combinations[i].size(); j++){
                if (combinations[i][j] < vitaminReq[j]){
                    works = false;
                }
            }
            if (works){
                posScoops.clear();
                scoops = count(choice[i].begin(),choice[i].end(), 1);
                for(int j = 0; j<choice[i].size(); j++){
                    if (choice[i][j]==1){
                        posScoops.push_back(j+1);
                    }
                }
            }
        }
    }

    sort(posScoops.begin(), posScoops.end());
    fout << scoops << " ";
    int numscoops = posScoops.size();
    for(int i = 0; i<numscoops-1;i++){
        fout << posScoops[i]  << " ";
    }
    fout <<  posScoops[numscoops-1] << endl;
    return 0;
}
