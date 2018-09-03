#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

typedef set<pair<int,int>>::iterator sit;

int points[5], T, G;
set<pair<int,int>> matches;

int solve(sit it){
    if(it==matches.end()){
        for(int i=1; i<=4; i++){
            if(i==T) continue;
            if(points[i]>=points[T]) return 0;
        }
        return 1;
    }
    int ans = 0;
    int a = (*it).first;
    int b = (*it).second;
    sit to = it;
    to++;
    points[a]+=3;
    ans += solve(to);
    points[a]-=3;
    points[b]+=3;
    ans += solve(to);
    points[b]-=2;
    points[a]++;
    ans += solve(to);
    points[b]--;
    points[a]--;
    return ans;
}

int main(){
    cin >> T >> G;
    for(int i=1; i<4; i++){
        for(int j=i+1; j<=4; j++) matches.insert({i, j});
    }
    for(int i=0; i<G; i++){
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        matches.erase({a, b});
        if(sa>sb) points[a]+=3;
        else if(sb>sa) points[b]+=3;
        else{
            points[a]++;
            points[b]++;
        }
    }
    cout << solve(matches.begin()) << endl;
    return 0;
}
