/*
ID: anish.51
LANG: C++
TASK: sort3
*/
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;
map<int,int> counterMap;
map<int,int> incorrectlyPlaced;
map<int,int>::iterator it;
map<int,int>::iterator it2;
vector<int> sequence;
vector<int> propseq;
int swaps;
void incorrectPlaced(){
    incorrectlyPlaced.clear();
    for(int i = 0; i<sequence.size(); i++){
        if(i<counterMap[1] && sequence[i] != 1){
            incorrectlyPlaced[i] = sequence[i];
        }
        else if (counterMap[1] <= i && counterMap[2]+counterMap[1] > i && sequence[i]!=2){
            incorrectlyPlaced[i] = sequence[i];
        }
        else if(counterMap[2]+counterMap[1] <= i && sequence[i]!=3){
            incorrectlyPlaced[i] = sequence[i];
        }
    }
}
void sort1(){
    incorrectPlaced();
    for(it = incorrectlyPlaced.begin(); it!= incorrectlyPlaced.end(); it++){
        for(it2 = incorrectlyPlaced.begin(); it2!= incorrectlyPlaced.end(); it2++){
            if (propseq[it->first] == it2->second && propseq[it2->first] == it->second && it2->second!=it->second){
                sequence[it->first] = propseq[it->first];
                sequence[it2->first] = propseq[it2->first];
                incorrectlyPlaced[it2->first] = -1;
                incorrectlyPlaced[it->first] = -1;
                swaps+=1;
            }
        }
    }
}
void sort2(){
    while (sequence!=propseq){
        incorrectPlaced();
        for(int i = 0; i<propseq.size();i++){
            if(propseq[i]!=sequence[i] && propseq[i] == incorrectlyPlaced.begin()->second){
                sequence[incorrectlyPlaced.begin()->first] = sequence[i];
                sequence[i] = propseq[i];
                swaps+=1;
                break;
            }
        }
    }

}
int N;
int main()
{
    counterMap[1] = 0;
    counterMap[2]  = 0;
    counterMap[3] = 0;

    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");

    fin >> N;
    for(int i = 0; i < N; i++){
        int a;
        fin >> a;
        counterMap[a]+=1;
        sequence.push_back(a);
    }
    for(int i = 0; i<N; i++){
        if (counterMap[2]+counterMap[1] <= i){
            propseq.push_back(3);
        }
        else if (counterMap[1]<=i){
            propseq.push_back(2);
        }
        else{
            propseq.push_back(1);
        }
    }
    sort1();
    sort2();
    fout << swaps << endl;

    return 0;
}
