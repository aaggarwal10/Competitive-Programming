/*
ID: anish.51
PROB: msquare
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <queue>
#include<string>
#include<algorithm>
using namespace std;

unordered_set<string> hashTab = {};
string finalState = "";
string initState = "12345678";
ifstream fin ("msquare.in");
ofstream fout ("msquare.out");

string TransformA(string item){
    string newItem = item;
    reverse(newItem.begin(),newItem.end());
    if(hashTab.find(newItem)!=hashTab.end()){
        return "";
    }
    else{
        hashTab.insert(newItem);
        return newItem;
    }
}
string TransformB(string item){
    string partA = item.substr(0,4);
    string partB = item.substr(4,4);
    rotate(partA.rbegin(),partA.rbegin()+1,partA.rend());
    rotate(partB.begin(),partB.begin()+1,partB.end());

    string newItem = partA + partB;
    if(hashTab.find(newItem)!=hashTab.end()){
        return "";
    }
    else{
        hashTab.insert(newItem);
        return newItem;
    }
}

string TransformC (string item){
    string newItem = "";
    newItem+=item.at(0);
    newItem+=item.at(6);
    newItem+=item.at(1);
    newItem+=item.at(3);
    newItem+=item.at(4);
    newItem+=item.at(2);
    newItem+=item.at(5);
    newItem+=item.at(7);
    if(hashTab.find(newItem)!=hashTab.end()){
        return "";
    }
    else{
        hashTab.insert(newItem);
        return newItem;
    }
}
int main()
{
    for(int i = 0; i<8; i++){
        char c;
        fin >> c;
        finalState+=c;
    }

    hashTab.insert(initState);

    queue<pair<string,string>> states;
    states.push(make_pair(initState,""));


    while(!states.empty()){
        pair<string,string> item = states.front();
        states.pop();
        string curState = item.first;
        string curPath = item.second;
        if(curState==finalState){
            fout << curPath.size()<< endl;
            if(curPath.size()==0){
                fout << endl;
            }
            int numSub = curPath.size()/60;
            for(int i = 0; i<numSub; i++){
                fout << curPath.substr(i*60,60) << endl;
            }
            if(curPath.size()%60!=0){
                fout << curPath.substr(60*numSub) << endl;
            }
            break;
        }
        else{
            string aState = TransformA(curState);
            if(!aState.empty()){
                states.push(make_pair(aState,curPath+"A"));
            }
            string bState = TransformB(curState);
            if(!bState.empty()){
                states.push(make_pair(bState,curPath+"B"));
            }
            string cState = TransformC(curState);
            if(!cState.empty()){
                states.push(make_pair(cState,curPath+"C"));
            }

        }

    }



    return 0;
}
