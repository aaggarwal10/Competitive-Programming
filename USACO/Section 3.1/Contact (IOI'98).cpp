/*
ID: anish.51
PROB:contact
LANG: C++
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

map<string,int> occurs;
map<string,int>::iterator it;
map<int,vector<string>> countOfOcc;
map<int,vector<string>> lastFew;
map<int,vector<string>>::reverse_iterator it2;
int A,B,N;
string binStr;
vector<string> bins;
ifstream fin("contact.in");
ofstream fout ("contact.out");


void specialSort(){
    vector<pair<int,string>> sortedList;
    for(int i = 0; i<bins.size();i++){
        sortedList.push_back(make_pair(bins[i].length(), bins[i]));
    }
    sort(sortedList.begin(),sortedList.end());
    for(int i = 0; i<sortedList.size(); i++){
        bins[i] = sortedList[i].second;
    }
}
void makeBinSameLength(){
    int maxSize = 0;
    for(int i = 0; i<bins.size(); i++){
        if(bins[i].length()>maxSize){
            maxSize = bins[i].length();
        }
    }
    for(int i = 0; i<bins.size(); i++){
        while(bins[i].length()!=maxSize){
            bins[i] = "0"+bins[i];
        }
    }
}
int main()
{
    fin >> A >> B >> N;
    while (fin.good()){
        string bin;
        fin >>  bin;
        binStr+=bin;
    }
    for(int i = 0; i<binStr.length(); i++){
        for(int j = A; j<=B && i+j<=binStr.length(); j++){
            string a = binStr.substr(i,j);
            if(occurs.find(a)==occurs.end()){
                occurs[a]=1;
            }
            else{
                occurs[a]+=1;
            }
        }
    }

    for(it = occurs.begin(); it!=occurs.end(); it++){
        countOfOcc[it->second].push_back(it->first);
    }
    for(int i = 0 ;i<N; i++){
        if(countOfOcc.empty()){
            break;
        }
        lastFew[countOfOcc.rbegin()->first] = countOfOcc.rbegin()->second;
        countOfOcc.erase(countOfOcc.rbegin()->first);
    }

    for(it2 = lastFew.rbegin(); it2!=lastFew.rend(); ++it2){
        fout << it2->first << endl;
        bins = it2->second;
        specialSort();
        int countIt = 0;
        for(int i = 0; i<bins.size(); i++){
            fout << bins[i];
            countIt++;
            if(countIt%6==0||i==bins.size()-1){
                fout << endl;
            }
            else{
                fout << " ";
            }
        }

    }



    return 0;
}
