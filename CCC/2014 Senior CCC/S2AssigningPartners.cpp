#include <iostream>
#include <map>

using namespace std;

//Global Variables
map<string,string> partners;
string partnersA[30];
string partnersB[30];
int N;
bool printed = false;

int main()
{
    cin >> N;
    for (int i = 0; i<N; i++){
        cin >> partnersA[i];
    }
    for (int i = 0; i<N; i++){
        cin >> partnersB[i];
    }
    for (int i = 0; i<N; i++){
        if (partnersA[i]!=partnersB[i]){
            if(partners.find(partnersA[i]) == partners.end() && partners.find(partnersB[i]) == partners.end()){
                partners[partnersA[i]] = partnersB[i];
                partners[partnersB[i]] = partnersA[i];
            }
            else if(partners.find(partnersA[i]) != partners.end() && partners.find(partnersB[i]) != partners.end()){
                if (partners[partnersA[i]] != partnersB[i] || partners[partnersB[i]] != partnersA[i]){
                    cout << "bad\n";
                    printed = true;
                    break;
                }
            }
            else{
                cout << "bad\n";
                printed = true;
                break;
            }
        }
        else{
            cout << "bad\n";
            printed = true;
            break;
        }
    }
    if(!printed){
        cout << "good\n";
    }
    return 0;
}
