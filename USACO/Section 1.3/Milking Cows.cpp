/*
ID: anish.51
PROB: milk2
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int N;
vector< pair<int,int> > timeTable;
vector< pair<int,int> > inputTimes;
int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    fin >> N;
    for (int i = 0; i<N; i++){
        int input1;
        int input2;
        fin >> input1 >> input2;
        inputTimes.push_back(make_pair(input1,input2));
    }
    sort(inputTimes.begin(), inputTimes.end());
    for (int i = 0; i<N; i++){
        int firs = inputTimes[i].first;
        int secon = inputTimes[i].second;
        bool alreadyAppended = false;
        if (!timeTable.empty()){
            for (int n = 0; n < timeTable.size(); n++){
                if(timeTable[n].first<=firs && firs<=timeTable[n].second){
                    if(secon>timeTable[n].second){
                        timeTable[n].second = secon;
                    }
                    alreadyAppended = true;
                }
                else if(timeTable[n].first<=secon && secon<=timeTable[n].second){
                    if (firs<timeTable[n].first){
                        timeTable[n].first = firs;
                    }
                    alreadyAppended = true;
                }
            }
        }
        if(timeTable.empty() || (!alreadyAppended)){
            timeTable.push_back(make_pair(firs,secon));
        }
    }

    sort(timeTable.begin(),timeTable.end());
    int maxDiff = 0;
    int maxTimeInbetween = 0;
    for (int i = 0; i<timeTable.size(); i++){
        if (maxDiff < (timeTable[i].second - timeTable[i].first)){
            maxDiff = timeTable[i].second - timeTable[i].first;
        }
        if (i>0){
            if (maxTimeInbetween<(timeTable[i].first - timeTable[i-1].second)){
                maxTimeInbetween = timeTable[i].first - timeTable[i-1].second;
            }
        }
    }
    fout << maxDiff << " " << maxTimeInbetween << endl;
}
