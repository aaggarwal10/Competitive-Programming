/*
ID: anish.51
LANG: C++
TASK: runround
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
vector<long> num;
vector<long> curNum;
long N;
bool hasDuplicates(const vector<long>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        for (std::size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] == arr[j])
                return true;
        }
    }
    return false;
}
bool numCycles(){
    vector<int> places;
    vector<int> correctPlaces;
    for(int i = 0; i<curNum.size(); i++){
        correctPlaces.push_back(i);
        if (curNum[i] == 0){
            return false;
        }
    }
    if(hasDuplicates(curNum)){
        return false;
    }
    int curIndex = 0;
    while (true){
        curIndex = (curIndex+curNum[curIndex])%curNum.size();
        if(find(places.begin(),places.end(),curIndex)==places.end()){
            places.push_back(curIndex);
        }
        else{
            break;
        }
        if (curIndex == 0){
            break;
        }
    }
    if (places.back()!=0){
        return false;
    }
    sort(places.begin(),places.end());
    if (places!=correctPlaces){
        return false;
    }
    return true;

}
void splitDigits(long n){
    curNum.clear();
    while (n > 0){
        curNum.push_back(n%10);
        n/=10;
    }
    reverse(curNum.begin(),curNum.end());
}
int main()
{
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    fin >> N;
    while(true){
        ++N;
        splitDigits(N);
        if (numCycles()){
            fout << N << endl;
            break;
        }
    }
    return 0;
}
