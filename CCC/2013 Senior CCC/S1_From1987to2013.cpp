#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> digits;
vector<int> uniqueDigits;

bool found(int k){
    for(int i = 0; i<digits.size(); i++){
        if (digits[i] == k){
            return true;
        }
    }
    return false;
}

bool splitToDigits(int year){
    digits.clear();
    while (year!=0){
        if (found(year%10)){
            splitToDigits(++N);
            break;
        }
        else{
            digits.push_back(year%10);
            year /= 10;
        }
    }
    if(year == 0){
        cout<<N;
    }
}

int main()
{
    cin >>  N;
    splitToDigits(++N);
    return 0;
}
