/*
ID: anish.51
PROB: milk
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> > farmerMilkCosts;

int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int N,M;
    fin >> N >> M;
    for (int i=0; i<M; i++){
        int P,A;
        fin >> P >> A;
        farmerMilkCosts.emplace(P,A);
    }
    int totCost = 0;
    int amountTaken = 0;
    while(amountTaken!=N){
        if (farmerMilkCosts.top().second+amountTaken<=N){
            amountTaken+=farmerMilkCosts.top().second;
            totCost += farmerMilkCosts.top().second*farmerMilkCosts.top().first;
        }
        else{
            totCost += (N-amountTaken)*farmerMilkCosts.top().first;
            amountTaken+=N-amountTaken;

        }
        farmerMilkCosts.pop();
    }
    fout << totCost << endl;
    return 0;
}
