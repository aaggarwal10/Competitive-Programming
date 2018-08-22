/*
ID: anish.51
LANG: C++
TASK: hamming
*/
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
vector<int> codewords;
int hammingDistance(int a, int b){
    int hammingDist=0;
    string binA = bitset<8>(a).to_string();
    string binB = bitset<8>(b).to_string();
    for(int i = 0; i<8; i++){
        if (binA[i]!=binB[i]){
            hammingDist+=1;
        }
    }
    return hammingDist;

}
int N,D,B;
int main()
{
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    fin >> N >> B >> D;
    codewords.push_back(0);
    for(int i = 1; i<pow(2,B); i++){
        bool works = true;
        if (codewords.size()==N){
            break;
        }
        for(int j = 0; j<codewords.size(); j++){
            int codeWord = codewords[j];
            if (hammingDistance(codeWord,i)<D){
                works = false;
            }
        }
        if (works){
            codewords.push_back(i);
        }
    }
    while (!codewords.empty()){
        int counter = 0;
        while (counter!=10){
            if (codewords.empty()){
                break;
            }
            if (codewords.size()==1 || counter==9){
                fout << codewords[0];
            }
            else{
                fout << codewords[0] << " ";
            }
            codewords.erase(codewords.begin(),codewords.begin()+1);
            counter+=1;
        }
        fout << "\n";
    }
    return 0;
}
