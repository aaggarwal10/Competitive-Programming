/*
ID: anish.51
PROB: dualpal
LANG: C++
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char digits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
string switchBase(int N, int B){
    string num ="";
    int quotient=N;
    while (quotient!=0){
        num = digits[quotient%B] + num;
        quotient = quotient/B;
    }
    return num;
}
int N,S;
int main()
{
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    fin >> N >> S;
    while (N!=0){
        S+=1;
        int palCount=0;
        for(int i=2;i<11;i++){
           if (palCount==2){
                break;
           }
           string reversed = switchBase(S,i);
           string normal = reversed;
           reverse(reversed.begin(),reversed.end());
           if(normal == reversed){
                palCount+=1;
           }
        }
        if (palCount==2){
            N-=1;
            fout << S << endl;
        }
    }
    return 0;
}
