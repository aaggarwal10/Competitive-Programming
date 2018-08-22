#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> friendlist;
int main()
{
    cin >> N >> M;
    for (int i = 0; i<N; i++){
        friendlist.push_back(i+1);
    }

    for (int i = 0; i<M; i++){
        int removal;
        cin >> removal;
        vector<int> friendlist2;
        for (int i = 0; i<friendlist.size(); i++){
            if ((i+1)%removal != 0){
                friendlist2.push_back(friendlist[i]);
            }
        }
        friendlist = friendlist2;
    }
    for (int i = 0; i< friendlist.size(); i++){
        cout << friendlist[i]<<endl;
    }
}
