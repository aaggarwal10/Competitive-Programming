/*
ID: anish.51
PROB: fence9
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
pi points[3];
int n,m,p;

int gcd(int a, int b){
    return (b==0)?a:gcd(b,a%b);
}
int pointsInBetween(pi p1, pi p2){
    if(p1.first == p2.first){
        return abs(p2.second-p1.second)-1;
    }
    else if(p1.second == p2.second){
        return abs(p1.first-p2.first)-1;
    }
    p2.second -= p1.second;
    p2.first -= p1.first;
    p1.first = p1.second = 0;
    p2.first = abs(p2.first);
    p2.second = abs(p2.second);
    int div = p2.second/gcd(p2.first,p2.second);
    int c = 0;
    for(int p = div; p<p2.second; p+=div){
        c++;
    }
    return c;
}

int main()
{
#ifndef LOCAL
    ifstream cin("fence9.in");
    ofstream cout("fence9.out");
#endif
    points[0] = make_pair(0,0);
    cin >> n >> m >> p;
    points[1] = make_pair(n,m);
    points[2] = make_pair(p,0);
    int borderLatice = 3+pointsInBetween(points[0],points[2])+pointsInBetween(points[0],points[1])+pointsInBetween(points[1],points[2]);
    if(p*m == 0){
        cout << 0 << endl;
        return 0;
    }
    cout <<((p*m-borderLatice)/2+1)<<endl;

    return 0;
}
