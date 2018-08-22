#include <iostream>
#include <map>
using namespace std;


int jerseys [10000002];
int counter = 0;
int main()
{
    map<string,int> sizeMap;
    sizeMap["L"]=2;
    sizeMap["M"]=1;
    sizeMap["S"]=0;
    int jerseysNum;
    int athletesNum;
    cin >> jerseysNum >> athletesNum;
    for (int i = 0; i<jerseysNum; i++){
        string jerSize;
        cin >> jerSize;
        jerseys[i] = sizeMap[jerSize];
    }
    for (int i = 0; i<athletesNum; i++){
        string wantedSize;
        int wantedNumber;
        cin >> wantedSize >> wantedNumber;
        int realwantedSize = sizeMap.find(wantedSize)->second;
        if (jerseys[wantedNumber-1]>=realwantedSize){
            jerseys[wantedNumber-1]=-1;
            counter+=1;
        }
    }
    cout << counter <<endl;
}
