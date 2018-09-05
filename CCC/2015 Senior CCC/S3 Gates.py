#include <iostream>

using namespace std;
int G,P;
int gates[100001];
int counter = 0;
int isAvaillable(int x){
    if (gates[x] == x){
        return x;
    }
    else{
        gates[x] = isAvaillable(gates[x]);
        return gates[x];
    }
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> G >> P;
    for(int i = 0; i<100001; i++){
        gates[i] = i;
    }
    for(int i = 0; i<P; i++){
        int g;
        cin >> g;
        int firstGate = isAvaillable(g);
        //cout << firstGate << endl;
        if(firstGate>0){
            counter += 1;
            gates[firstGate] = isAvaillable(firstGate-1); // find next gate
        }
        else{
            break;
        }
    }
    cout << counter << endl;
    return 0;
}
