/*
ID: anish.51
PROB: zerosum
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int N;
int arr[10];
vector<string> check;
vector<string> ans;
int sumASCII(string asciiStr){
    int sum = 0;
    for(int i = 0; i<asciiStr.length(); i++)
        sum+=(int)asciiStr[i];
    return sum;
}
bool sumIs0(string evalstr){
    int sum = 0;
    vector<int> nums;
    vector<string> signs;
    signs.push_back("+");
    string newStr = "";
    for(int i = 0; i<evalstr.length(); i++){
        if (evalstr[i] !=  ' '){
            newStr+=evalstr[i];
        }
    }
    int start = 0;
    int finish;
    for(finish = 0; finish<newStr.length(); finish++){
        if(newStr[finish] == '+' || newStr[finish] == '-'){
            nums.push_back(stoi(newStr.substr(start,finish-start)));
            start = finish+1;
            signs.push_back(string (1,newStr[finish]));
        }

    }
    nums.push_back(stoi(newStr.substr(start,finish-start)));

    for(int i = 0; i<nums.size(); i++){
        if (signs[i]=="+"){
            sum+=nums[i];
        }
        else{
            sum-=nums[i];
        }
    }
    if (sum == 0){
        ans.push_back(evalstr);
    }
}
void rec(string str, int counter){
    if (counter>N){
        sumIs0(str);
    }
    else{
        string str1 = str;
        string str2 = str;
        string str3 = str;
        str1+="+"+to_string(counter);
        str2+="-"+to_string(counter);
        str3+=" "+to_string(counter);
        counter+=1;
        rec(str1,counter);
        rec(str2,counter);
        rec(str3,counter);
    }
}
int main()
{
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");
    fin >> N;
    rec("1",2);
    sort(ans.begin(),ans.end());
    for(int i = 0; i<ans.size(); i++){
        fout << ans[i] << endl;
    }

}
