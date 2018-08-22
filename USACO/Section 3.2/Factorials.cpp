/*
ID: anish.51
PROB: fact4
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int N,num;
int digits[5000] = {0};
long long prod=1;

ifstream fin("fact4.in");
ofstream fout("fact4.out");

int main()
{
    fin >> N;
    for(int i = 1; i<=N; i++){
        int num=i;
        while (1){
            if (num%2!=0 && num%5!=0){
                break;
            }
            if (num%2==0){
                digits[2]+=1;
                num/=2;
            }
            if(num%5==0){
                digits[2]-=1;
                num/=5;
            }
        }
        digits[num]+=1;
    }

    prod = 1;
    digits[2] %= 4;
    digits[3]%=4;
    if (digits[2]==0 && N>1){
        digits[2] = 4;
    }
    if(digits[3]==0 &&N>2){
        digits[3] = 4;
    }
    for(int i = 2; i<5000; i++){
        if(digits[i]){
            for(int j = 0; j<digits[i];j++){
                prod=(prod*i%10);
            }
        }
    }
    fout << prod%10 << endl;
    return 0;
}
