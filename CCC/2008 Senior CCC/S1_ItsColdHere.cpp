#include <iostream>

using namespace std;
string city,coldestCit;
int temp, coldestTemp;
int main()
{
    cin >> city >> temp;
    coldestCit = city;
    coldestTemp = temp;
    while (city!="Waterloo"){
        cin >> city >> temp;
        if(coldestTemp>temp){
            coldestTemp = temp;
            coldestCit = city;
        }
    }
    cout << coldestCit << endl;
    return 0;
}
