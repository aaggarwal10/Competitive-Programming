#include <iostream>

using namespace std;
int N;
int team1[1000000]={0};
int team2[1000000]={0};
bool notPrinted = true;
int main()
{

    cin >> N;

    for (int i = 0; i<N; i++){
        cin >> team1[i];
    }
    for (int i = 0; i<N; i++){
        cin >> team2[i];
    }

    for (int i = 1; i<N;i++){ //make the prefix array for both teams
        team1[i]+=team1[i-1];
        team2[i]+=team2[i-1];
    }
    for(int i = N-1; i>0; i--){//check if at any date the two are equal and if so print it
        if (team1[i]==team2[i]){
            cout << i << endl;
            notPrinted = false;
        }
    }
    if(notPrinted){//if nothing was printed that means it was equal on no date meaning print 0
        cout <<0<<endl;
    }
    return 0;
}
