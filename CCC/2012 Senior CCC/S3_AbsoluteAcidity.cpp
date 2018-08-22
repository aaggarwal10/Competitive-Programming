#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
int N;
int measurements[1001] ={0};
map<int,vector<int>> countPerMeas;
map<int,vector<int>>::iterator it;
int main()
{
    cin >> N;
    for(int i = 0; i<N; i++){
        int j;
        cin >> j;
        measurements[j]+=1;
    }
    for(int i = 0; i<1001; i++){
        if(measurements[i]){
            countPerMeas[measurements[i]].push_back(i);
        }
    }

    vector<int> mostFreq=countPerMeas.rbegin()->second;
    int minN = 10000000;
    int maxN = 0;
    if (mostFreq.size()>=2){
        for(int i = 0; i<mostFreq.size(); i++){
            if (minN>mostFreq[i]){
                minN = mostFreq[i];
            }
            if (maxN<mostFreq[i]){
                maxN=mostFreq[i];
            }
        }
        cout << maxN-minN << endl;
    }
    else{
        countPerMeas.erase(countPerMeas.rbegin()->first);
        vector<int> secondFreq=countPerMeas.rbegin()->second;
        maxN = mostFreq[0];
        int largestDiff = 0;
        for (int i = 0; i<secondFreq.size(); i++){
            if (abs(maxN-secondFreq[i])>largestDiff){
                largestDiff = abs(maxN-secondFreq[i]);
            }
        }
        cout << largestDiff << endl;
    }

    return 0;
}
