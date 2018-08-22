/*
ID: anish.51
LANG: C++
TASK: sprime
*/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
int firstDigit [] = {2,3,5,7};
int otherDigits [] = {1,3,7,9};
vector <string> possRibs;
int N;
bool isPrime(int n){
    if (n==2){
        return true;
    }
    if (n%2 == 0){
        return false;
    }
    for (int i=3; i<=sqrt(n); i+=2){
        if (n%i==0){
            return false;
        }
    }
    return true;
}
void recFindPoss(string cur,int lengh){
    if (cur.length() == lengh){
        possRibs.push_back(cur);
    }
    else if (cur.length() >= 1){
        for (int i = 0; i<4; i++){
            recFindPoss(cur+to_string(otherDigits[i]),lengh);
        }
    }
    else{
        for(int i = 0; i<4; i++){
            recFindPoss(to_string(firstDigit[i]),lengh);
        }
    }
}
int main()
{
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    fin >> N;
    recFindPoss("",N);
    for(int i = 0; i < possRibs.size(); i++){
        bool works = true;
        for (int n = 1; n<=N; n++){
            if (!isPrime(stoi(possRibs[i].substr(0,n)))){
                works = false;
            }
        }
        if (works){
            fout << possRibs[i] << endl;
        }
    }
    return 0;
}
