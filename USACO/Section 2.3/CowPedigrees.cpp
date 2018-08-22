/*
ID: anish.51
PROB: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int possTrees [201][101]; //possTrees [nodes][height] = count
int nodes,height;
int findTree(int a,int b){
    int sum=0;
    if(a==0 || b==0){
        return 0;
    }
    if(a==1){
        return 1;
    }
    if(possTrees[a][b]!=-1){
        return possTrees[a][b];
    }
    else{
        for(int i=1; i<a-1;i++){
            sum = (sum + findTree(i,b-1)*findTree(a-i-1,b-1))%9901;
        }
        possTrees[a][b]=sum;
        return sum;
    }
}
int main()
{
    for(int i = 0; i<201;i++){
        for(int j = 0; j<101;j++){
            possTrees[i][j] = -1;
        }
    }

    ifstream fin ("nocows.in");
    ofstream fout ("nocows.out");
    fin >> nodes >> height;
    fout << (9901+findTree(nodes,height)-findTree(nodes,height-1))%9901 << endl;
    return 0;
}
