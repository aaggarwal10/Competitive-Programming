#include <iostream>

using namespace std;

int N;

int main()
{
    cin >> N;
    if (N<=3){
        cout << 0 << endl;
    }
    else{
        cout << (N-1)*(N-2)*(N-3)/(3*2)<<endl;
    }

    return 0;
}
