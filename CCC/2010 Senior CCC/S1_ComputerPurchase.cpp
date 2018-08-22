#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int R,S,D;
string name;

vector<pair<int,string>> computerCategory;
bool sortfunc(pair<int,string>itemA,pair<int,string>itemB){
    if(itemA.first!=itemB.first){
        return itemA.first<itemB.first;
    }
    else{
        if(itemA>itemB){
            return true;
        }
        return false;
    }
}
int main()
{
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> name >> R >> S >> D;
        computerCategory.push_back(make_pair(2*R+3*S+D, name));
    }
    sort(computerCategory.begin(),computerCategory.end(),sortfunc);
    if(N!=0;){
        cout << computerCategory[N-1].second << endl;
        cout << computerCategory[N-2].second << endl;
    }
    return 0;
}
