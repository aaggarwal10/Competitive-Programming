/*
ID: anish.51
PROB: rockers
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;


int N,M,T;
int cdSizes[21];


int rec(vector<int> cds, int cdPointer, int numSongs){
    if(cdPointer==N){
        return numSongs;
    }
    else{
        vector<int> temp = cds;
        int tempSongs = numSongs;
        if(cds.back()+cdSizes[cdPointer]<=T){
            temp[temp.size()-1] += cdSizes[cdPointer];
            tempSongs+=1;
        }
        else if(cds.back()+cdSizes[cdPointer]>T&&cds.size()<M&&cdSizes[cdPointer]<=T){
            temp.push_back(cdSizes[cdPointer]);
            tempSongs+=1;
        }
        if(tempSongs!=numSongs)
            return max(rec(cds,cdPointer+1, numSongs),rec(temp,cdPointer+1,tempSongs));
        return rec(cds,cdPointer+1,numSongs);
    }
}
int main()
{
#ifndef LOCAL
    ifstream cin("rockers.in");
    ofstream cout("rockers.out");
#endif
    cin >> N >> T >> M;
    for(int i = 0; i<N; i++){
        cin >> cdSizes[i];
    }
    vector<int> cdChosen;
    cdChosen.push_back(0);


    cout << rec(cdChosen,0,0) << endl;
    return 0;
}
