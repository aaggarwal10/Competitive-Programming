/*
ID: anish.51
PROB: concom
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int shares[101][101]={0};
int controls[101][101]={0};
int N;

void add_owner(int i,int j);

void check_shares(int i){
    for(int k = 0; k<101;k++){
        if (shares[i][k]>50){
            add_owner(i,k);
        }
    }
}
void add_owner(int i, int j){
    if (controls[i][j]){
        return;
    }
    controls[i][j] = 1;

    for(int k = 0; k<101; k++){
        shares[i][k]+=shares[j][k];
    }
    for(int k = 0; k<101; k++){
        if(controls[k][i]){
            add_owner(k,j);
        }
    }
    check_shares(i);
}

void add_share(int i, int j, int p){
    //add p of j to each owner of i (P.S. i owns i)
    for(int k = 0; k<101; k++){
        if (controls[k][i]){
            shares[k][j]+=p;
            check_shares(k);
        }
    }
}

int main()
{
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    fin >> N;
    for (int i = 0; i<101; i++){
        controls[i][i] = 1;

    }
    for(int i = 0; i<N; i++){
        int a,b,s;
        fin >> a >> b >> s;
        add_share(a,b,s);
    }
    for(int i = 0; i<101; i++){
        for(int j=0; j<101; j++){
            if (controls[i][j] && i!=j){
                fout << i << " " << j << endl;
            }
        }
    }
    return 0;
}
