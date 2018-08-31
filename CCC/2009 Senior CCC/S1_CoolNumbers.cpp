#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int A, B;
int counter = 0;
int main()
{
    cin >> A >> B;
    for(int i = 1; i<=pow(B,1/6.)+1; i++){
        if(A<= i*i*i*i*i*i && i*i*i*i*i*i<=B){
            counter+=1;
        }
    }
    cout << counter << endl;
    return 0;
}
