#include <iostream>

using namespace std;
unsigned long check = 1989*10000 + 2 * 100 + 27;
unsigned long a,b,c;
int N;
int main()
{
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> a >> b >> c;
        if(check>=a*10000+b*100+c){
            cout << "Yes"<<endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
