/*
ID: anish.51
PROB: palsquare
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
int base;
int main()
{
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    fin >> base;
    for (int i = 1; i<301; i++){
        string reversed = switchBase(i*i,base);
        string normal = reversed;
        reverse(reversed.begin(),reversed.end());
        if(normal == reversed){
            fout <<  switchBase(i,base) << " " << normal<<endl;
        }
    }
    return 0;
}
