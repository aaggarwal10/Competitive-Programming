/*
ID: anish.51
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
int NP;
map<string,int> bankOfLife;
map<string, int>::iterator it;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin >> NP;
    string names[NP];
    for (int i=0; i<NP;i++){
        string name;
        fin >> name;
        names[i] = name;
        bankOfLife[name]=0;
    }
    for (int i=0; i<NP; i++){
        string client;
        int donatingTo;
        int donation;
        fin >> client;
        fin >> donation;
        fin >> donatingTo;
        if (donatingTo!=0){
            bankOfLife[client]+=donation%donatingTo;
            bankOfLife[client]-= donation;
        }
        else{
            bankOfLife[client]+=donation;
        }
        for (int n = 0; n<donatingTo;n++){
            string receiver;
            fin >> receiver;
            bankOfLife[receiver]+= donation/donatingTo;
        }
    }
    for (int i = 0; i<NP; i++){
        fout<<names[i] << " "<< bankOfLife[names[i]] <<endl;
    }
    return 0;
}
