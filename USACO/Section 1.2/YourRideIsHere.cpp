/*
ID: anish.51
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string cometName, groupName;
inline int getProductChar(string str){
    int sumofLet=1;
    for (int i = 0; i<str.length(); i++){
        int let = str.at(i);
        sumofLet*=(let-64);
    }
    return sumofLet;
}
int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    getline(fin,cometName);
    getline(fin,groupName);
    int sumofLetters1 = getProductChar(cometName);
    int sumofLetters2 = getProductChar(groupName);
    if((sumofLetters1%47)==(sumofLetters2%47)){
        fout << "GO" << endl;;
    }
    else{
        fout << "STAY" << endl;
    }
    return 0;
}
