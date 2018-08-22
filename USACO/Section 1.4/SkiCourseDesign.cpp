/*
ID: anish.51
LANG: C++
TASK: skidesign
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;
int N;
int minCost = 1000000000;
int totCost=0;
int hills[1000];
int main()
{
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    fin >> N;
    for (int i = 0; i<N; i++){
        fin >> hills[i];
    }
    sort(hills, hills+N);
    for(int i = 0; i<83; i++){
        int maxElevation = i+17;
        for(int j = 0; j<N; j++){
            if (hills[j]>maxElevation){
                totCost+=pow(hills[j]-maxElevation,2);
            }
            else if (i>hills[j]){
                totCost+=pow(i-hills[j],2);
            }
        }
        minCost = min(minCost, totCost);
        totCost = 0;
    }
    fout << minCost << endl;
    return 0;
}
