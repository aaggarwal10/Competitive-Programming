/*
ID: anish.51
PROB: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;
int N;
string necklace;
int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    fin >> N;
    int counters[N*2] = {0};
    string neck;
    fin >> neck;
    necklace = neck + neck;
    for (int i=1; i<N*2; i++){
        string firstStr = necklace.substr(0,i);
        string secondStr = necklace.substr(i,N*2-i);
        reverse(firstStr.begin(),firstStr.end());
        char c = ' ';
        for (int n = 0; n<i; n++){
            if (c!=' '){
                if ((c != firstStr[n])&& (firstStr[n]!='w')){
                    break;
                }
                else{
                    counters[i]+=1;
                }
            }
            else{
                if(firstStr[n]!='w'){
                    c = firstStr[n];
                }
                counters[i]+=1;
            }
        }
        c = ' ';
        for (int n = 0; n<N*2-i; n++){
            if (c!=' '){
                if ((c != secondStr[n])&& (secondStr[n]!='w')){
                    break;
                }
                else{
                    counters[i]+=1;
                }
            }
            else{
                if(secondStr[n]!='w'){
                    c = secondStr[n];
                }
                counters[i]+=1;
            }
        }
    }
    int maxcount = 0;
    for (int n = 0; n<N*2; n++){
        if (counters[n] > maxcount){
            maxcount = counters[n];
        }
    }
    if (maxcount > N){
        maxcount = N;
    }
    fout << maxcount << endl;
    return 0;
}
