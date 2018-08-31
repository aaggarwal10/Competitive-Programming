#include <iostream>
#include <vector>
using namespace std;

int friendList[50][50]={0};
string command;
int personA, personB;

void makeEdge(int friendA, int friendB){
    friendList[friendA][friendB] = friendList[friendB][friendA] = 1;
}
int numFriend(int person, int notF = 0){
    int countFriends = 0;
    for(int i = 1; i<50;i++){
        if(friendList[person][i]&&i!=notF){
            countFriends+=1;
        }
    }
    return countFriends;
}
int shortestPathBFS(int friendA, int friendB){
    vector<int> que = {friendA};
    vector<int> FF;
    int visited[50] = {0};
    visited[friendA] = 1;
    int degreeOfS = 0;
    bool broken = false;
    while (!que.empty()){
        int curFriend = que.back();
        que.pop_back();
        for(int i = 0; i<50; i++){
            if (friendList[curFriend][i] && i == friendB){
                broken = true;
                break;
            }
            else if(friendList[curFriend][i] && !visited[i]){
                FF.push_back(i);
                visited[i] = 1;
            }
        }
        if (broken){
            break;
        }
        if (que.empty() && !FF.empty()){
            que = FF;
            FF.clear();
            degreeOfS+=1;
        }
    }
    if (!broken){
        return -1;
    }
    return degreeOfS+1;
}
int main(){
    //Initialize with starting graph
    makeEdge(2, 6);
	makeEdge(1, 6);
	makeEdge(7, 6);
	makeEdge(5, 6);
	makeEdge(4, 6);
	makeEdge(3, 6);
	makeEdge(3, 5);
	makeEdge(3, 4);
	makeEdge(5, 4);
	makeEdge(7, 8);
	makeEdge(9, 8);
	makeEdge(9, 10);
	makeEdge(9, 12);
	makeEdge(11, 10);
	makeEdge(11, 12);
	makeEdge(12, 13);
	makeEdge(15, 13);
	makeEdge(14, 13);
	makeEdge(15, 3);
	makeEdge(17, 16);
	makeEdge(17, 18);
	makeEdge(16, 18);

    //////////////////////////////////
    while (1){
        cin >> command;
        if(command == "i"){
            cin >> personA >> personB;
            makeEdge(personA,personB);
        }
        else if (command == "d"){
            cin >> personA >> personB;
            friendList[personA][personB] = 0;
            friendList[personB][personA] = 0;
        }
        else if(command == "n"){
            cin >> personA;
            cout << numFriend(personA) << endl;
        }
        else if(command =="f"){
            int numFF = 0;
            cin >> personA;
            vector<int> directF;
            int visited[50] = {0};
            visited[personA] = 1;
            for(int i = 0; i<50; i++){
                if(friendList[personA][i]){
                    directF.push_back(i);
                    visited[i] = 1;
                }
            }
            for(int i = 0; i<directF.size(); i++){
                for(int j = 0; j<50; j++){
                    if(friendList[directF[i]][j]&&!visited[j]){
                        numFF++;
                    }
                }
            }
            cout << numFF << endl;
        }
        else if(command == "s"){
            cin >> personA >> personB;
            int shortestP = shortestPathBFS(personA, personB);
            if(shortestP!=-1){
                cout << shortestP << endl;
            }
            else{
                cout << "Not connected" << endl;
            }
        }
        else{
            break;
        }

    }
    return 0;
}
