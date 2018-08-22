/*
ID: anish.51
LANG: C++
TASK: wormhole
*/
#include <iostream>
#include <fstream>
using namespace std;
int N;
int posX[13],posY[13];
int partners[13];
int next_on_right[13];
int LoopIsInf(){
    for (int i = 1; i<=N;i++){
        int pos = i;
        for (int c = 0; c<N; c++){
            pos = next_on_right[partners[pos]];
        }
        if (pos!=0){
            return true;
        }
    }
    return false;

}
int evaluatePortals(){
    int i,infLoops=0;
    for (i = 1; i<=N; i++){
        if (partners[i] == 0){
            break;
        }
    }
    if(i>N){
        if(LoopIsInf()){
            return 1;
        }
        else{
            return 0;
        }
    }
    for (int j = i+1; j<=N; j++){
        if(partners[j]==0){
            partners[i]=j;
            partners[j]=i;
            infLoops+= evaluatePortals();
            partners[i] = partners[j] = 0;
        }
    }
    return infLoops;
}
int main()
{
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    fin >> N;
    for (int i=1; i<=N; i++){
        fin >> posX[i] >> posY[i];
    }
    for (int i=1; i<=N; i++) // set next_on_right[i]...
        for (int j=1; j<=N; j++)
          if (posX[j] > posX[i] && posY[i] == posY[j]) // j right of i...
        if (next_on_right[i] == 0 ||
            posX[j]-posX[i] < posX[next_on_right[i]]-posX[i])
          next_on_right[i] = j;
    fout << evaluatePortals() << endl;
    return 0;
}
