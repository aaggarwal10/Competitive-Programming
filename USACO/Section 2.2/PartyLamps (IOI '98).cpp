/*
ID: anish.51
LANG: C++
TASK: lamps
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;
int N = 10, C;
map<int,int> lampState;
vector<int> lamps;
vector<vector<int>> workingStates;
vector<vector<int>> choice;
map<int,vector<vector<int>>> sortedChoices;
map<int,vector<vector<int>>>::iterator it;
void resetLamps(){
    lamps.clear();
    for(int i = 0; i<N; i++){
        lamps.push_back(1);
    }
}
void pushButton(int b){
    if(b==0){
        for(int i = 0; i<lamps.size(); i++){
            lamps[i] = (lamps[i]+1)%2;
        }
    }
    else if(b==1){
        for(int i = 0; i<lamps.size(); i++){
            if ((i+1)%2==0){
                lamps[i] = (lamps[i]+1)%2;
            }
        }
    }
    else if (b==2){
        for(int i = 0; i<lamps.size(); i++){
            if ((i+1)%2==1){
                lamps[i] = (lamps[i]+1)%2;
            }
        }
    }
    else{
        for(int i = 0; i<lamps.size(); i++){
            if (i%3==0){
                lamps[i] = (lamps[i]+1)%2;
            }
        }
    }
}
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
            if (it->first <= C){
                choice.push_back(it->second[i]);
            }
        }
    }
}
bool isInsideSet(){
    for(int i = 0; i<workingStates.size(); i++){
        if (workingStates[i]==lamps){
            return true;
        }
    }
    return false;
}
bool checkCombination(){
    for(int i = 0; i<lamps.size(); i++){
        if (lampState.find(i)!=lampState.end()){
                if(lampState[i] != lamps[i]){
                    return false;
                }
        }
    }
    return true;
}
void makeCombinations(){
    for(int i = 0; i<choice.size(); i++){
        resetLamps();
        for(int j = 0; j<choice[i].size(); j++){
            if (choice[i][j]==1){
                pushButton(j);
            }
        }
        if(checkCombination() && !isInsideSet()){
            workingStates.push_back(lamps);
        }
    }
}
int main()
{
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    fin >> N >> C;
    while (true){
        int a;
        fin >> a;
        if (a==-1){
            break;
        }
        else{
            lampState[a-1] = 1;
        }
    }
    while (true){
        int a;
        fin >> a;
        if (a==-1){
            break;
        }
        else{
            lampState[a-1] = 0;
        }
    }
    vector<int> emptyVect;
    addChoice(emptyVect, 4);
    sortChoice();
    resetLamps();
    pushButton(3);
    makeCombinations();
    sort(workingStates.begin(),workingStates.end());
    bool printed = false;
    for(int i = 0; i<workingStates.size(); i++){
        copy(workingStates[i].begin(),workingStates[i].end(),ostream_iterator<int>(fout));
        printed = true;
        fout << endl;
    }
    if (!printed){
        fout<<"IMPOSSIBLE\n";
    }
    return 0;
}
