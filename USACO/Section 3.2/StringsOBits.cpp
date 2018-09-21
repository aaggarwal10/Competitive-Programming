/*
ID: anish.51
PROB: kimbits
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;
int N,L;
unsigned long I;
vector<vector<int>> poss;
vector<int> que;
ifstream fin ("kimbits.in");
ofstream fout ("kimbits.out");
unsigned long long choosingGrid[33][33]={0};

long sumPoss(int N, int M){
    unsigned long sum = 0;
    for(int i = M; i>=0; i--){
        sum+=choosingGrid[N][i];
    }
    return sum;
}
int main()
{

    fin >> N >> L >> I;
    choosingGrid[0][0] = choosingGrid[1][0] = choosingGrid[1][1] = 1;
    for(int i = 2; i<=32; i++){
        for(int j = 0; j<=i; j++){
            if(j==i || j==0){
                choosingGrid[i][j] = 1;
            }
            else{
                choosingGrid[i][j] = choosingGrid[i-1][j-1]+choosingGrid[i-1][j];
            }
        }
    }
    long countPrev=0;
    for(int i = N; i>0; i--){
        if(L!=0 && sumPoss(i-1,min(L,i-1))+countPrev<I){
            countPrev+=sumPoss(i-1,min(L,i-1));
            L--;
            fout << "1";a
        }
        else{

            fout << "0";
        }
    }
    fout << endl;

    return 0;
}
