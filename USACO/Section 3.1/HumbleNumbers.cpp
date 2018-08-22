/*
ID: anish.51
PROB:humble
LANG: C++
*/
#include <iostream>
#include<fstream>
#include <map>
#include <set>
#include<limits.h>
#include <vector>

using namespace std;

int K,N,c;
int primes[101]={0};
const long INF = LONG_MAX;
int setSize = 0;
vector<long> cache;
ifstream fin("humble.in");
ofstream fout("humble.out");
long binSearch(int start, int finish, float target){
    int low = start, high = finish;
    while(low!=high){
        int mid = (low+high)/2;
        if (cache[mid]<target){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return cache[high];
}
int main()
{
    cache.push_back(1);
    fin >> K >> N;
    for(int i = 0; i<K; i++){
        int a;
        fin>>a;
        primes[i] = a;

    }
    while (cache.size()!=N+1){
        long minHumble = INF;
        for(int i = 0; i<K; i++){
            long prod = primes[i]*binSearch(0,cache.size(),(float)(cache.back()+1)/primes[i]);
            if(minHumble>prod){
                minHumble = prod;
            }
        }
        cache.push_back(minHumble);
    }
    fout << cache.back() << endl;
    return 0;
}
