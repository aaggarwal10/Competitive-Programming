#include <iostream>
#include<string>
#include <map>
using namespace std;

int N,substrSize = 1;
map<string, string> huffMan;
string bin,decode;

int main()
{
    cin >> N;
    for(int i = 0; i<N; i++){
        string a, b;
        cin >> a >> b;
        huffMan[b] = a;
    }
    cin >> bin;
    while (bin.length()){
        string charSub = bin.substr(0,substrSize);
        if (huffMan.find(charSub)!=huffMan.end()){
            decode+=huffMan[charSub];
            bin = bin.substr(substrSize,bin.length()-substrSize);
            substrSize=1;
        }
        else{
            substrSize++;
        }
    }

    cout << decode << endl;
    return 0;
}
