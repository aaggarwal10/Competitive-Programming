/*
 ID: anish.51
 PROG: prefix
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int longestPrefix[200001] = {1};
vector<string> primitives;
string seqToMake;

int main()
{
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    while (true) {
        string prim;
        fin >> prim;
        if (prim == ".") {
            break;
        }
        primitives.push_back(prim);
    }

    while (fin.good()) {
        string l;
        fin >> l;
        seqToMake += l;
    }

    int n = seqToMake.size();

    for (int i = 0; i <= n; ++i) {
        for (string word : primitives) {
            int start = i - (int)word.size();
            if(start >=0 && seqToMake.substr(start,word.size())==word && longestPrefix[start]){
                longestPrefix[i] = true;
            }
        }
    }

    for(int i = 200000; i>=0;i--){
        if(longestPrefix[i]){
            fout << i << endl;
            break;
        }
    }
    return 0;
}

