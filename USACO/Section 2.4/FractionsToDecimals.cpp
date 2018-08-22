/*
ID: anish.51
PROB: fracdec
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<int> digits;
int N,D,repeatedR = 0;
string output;
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
int remainder[100000] = {0};
inline void makeDecimal(){
    digits.push_back(N/D);
    N%=D;
    int c = 1;
    remainder[N] = c;
    while (N!=0){
        c++;
        N*=10;
        digits.push_back(N/D);
        if (remainder[N%D]){
            repeatedR = N%D;
            break;
        }
        N%=D;
        remainder[N]=c;
    }
}
inline void print(){
    int counter=0;
    for(char c:output){
        counter++;
        fout << c;
        if(counter%76 == 0){
            fout<<endl;
        }
    }
    fout<<endl;
}
int main()
{

    fin >> N >> D;
    makeDecimal();
    output= to_string(digits[0]) + ".";
    for(int i = 1;i<digits.size();i++){
        if (remainder[repeatedR] == i){
            output+= "(";
        }
        output += to_string(digits[i]);

    }
    if (digits.size()==1){
        output+="0";
    }
    else if (repeatedR){
        output+=")";
    }
    print();
    return 0;
}
