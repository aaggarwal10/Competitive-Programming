/*
ID: anish.51
LANG: C++
TASK: ariprog
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
int bisquares[251*251*2] = {0};
typedef pair<int,int> p;
priority_queue<p,vector<p>,greater<p>> answers;
int N,M;
int main()
{
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    fin >> N >> M;
    for(int p = 0; p<=M;p++){
        for(int q=0; q<=M; q++){
            bisquares[p*p+q*q] = 1;
        }
    }
    int maxVal = 2*M*M;
    for(int a = 0; a<=(maxVal-N);a++){
        for(int b = 1; b<=(maxVal-a)/(N-1); b++){
            bool works = true;
            for(int n=0; n<N; n++){
                if (bisquares[a+n*b]==0){
                    works = false;
                    break;
                }
            }
            if (works){
                answers.emplace(b,a);
            }
        }
    }
    bool printed = false;
    while (!answers.empty()){
        fout << answers.top().second << " " << answers.top().first << "\n";
        printed = true;
        answers.pop();
    }
    if (!printed){
        fout << "NONE\n";
    }
    return 0;
}
