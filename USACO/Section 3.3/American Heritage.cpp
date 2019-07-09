/*
ID: anish.51
PROB: heritage
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

string pre,in;
struct node{
    string data="";
    struct node* left;
    struct node* right;
};

struct node* newNode(string data){
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;

}
int findFirstNodeInd(string s){
    for(char c : pre){
        for(int i = 0; i<s.size(); i++){
            if(c==s.at(i)){
                return i;
            }
        }
    }
    return -1;
}
string makePost(node* root){
    string dataL="";
    string dataR="";
    if(root->left!=NULL){
        dataL = makePost(root->left);
    }
    if(root->right!=NULL){
        dataR = makePost(root->right);
    }
    return dataL+dataR+root->data;
}
int main()
{
#ifndef LOCAL
    ifstream cin("heritage.in");
    ofstream cout("heritage.out");
#endif
    cin >> in >> pre ;
    struct node* parent = newNode(in);
    queue<node*> bfs;
    bfs.push(parent);
    while(!bfs.empty()){
        node* curNode = bfs.front();
        bfs.pop();

        string info = curNode->data;
        if(info.size()>1){
            int ind = findFirstNodeInd(info);
            curNode->left =newNode(info.substr(0,ind));
            curNode->right = newNode(info.substr(ind+1));
            curNode->data = info.at(ind);
            bfs.push(curNode->left);
            bfs.push(curNode->right);
        }
    }
    cout << makePost(parent) << endl;
    return 0;
}
