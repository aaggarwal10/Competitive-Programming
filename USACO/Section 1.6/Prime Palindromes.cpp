/*
ID: anish.51
LANG: C++
TASK: pprime
*/
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;
int a,b;
vector<int> palindromes;
bool isPrime(int n){
    if (n%2 == 0){
        return false;
    }
    for (int i=3; i<=sqrt(n); i+=2){
        if (n%i==0){
            return false;
        }
    }
    return true;
}
void makePalindromes(){
    //1 and 2 digit;
    for (int d1 = 1; d1<10; d1++){
        palindromes.push_back(d1);
        palindromes.push_back(d1*10+d1);
    }
    //3 digit and 4 digit
    for (int d1 = 1; d1<10; d1++){
        for (int d2 = 0; d2 <10; d2 ++){
            palindromes.push_back(d1*1000+d2*100+d2*10+d1);
            palindromes.push_back(d1*100 + d2*10 + d1);
        }
    }
    //5 digit and 6 digit
    for (int d1 = 1; d1 < 10; d1++){
        for (int d2 = 0; d2<10; d2++){
            for (int d3 = 0; d3<10; d3++){
                palindromes.push_back(d1*10000+d2*1000+d3*100+d2*10+d1);
                palindromes.push_back(d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1);
            }
        }
    }
    //7 digit and 8 digit
    for (int d1 = 1; d1 <10; d1++){
        for (int d2 = 0; d2 < 10; d2 ++){
            for (int d3 = 0; d3<10; d3 ++){
                for (int d4 = 0; d4 < 10; d4++){
                    palindromes.push_back(1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1);
                    palindromes.push_back(10000000*d1 + 1000000*d2 + 100000*d3 +10000*d4 + 1000*d4 + 100*d3 + 10*d2 + d1);
                }
            }
        }
    }
    //9 digit
    for (int d1 = 1; d1 <10; d1++){
        for (int d2 = 0; d2 < 10; d2 ++){
            for (int d3 = 0; d3<10; d3 ++){
                for (int d4 = 0; d4 < 10; d4++){
                    for(int d5 = 0; d5 < 10; d5++){
                        palindromes.push_back(100000000*d1 + 10000000*d2 + 1000000*d3 + 100000*d4 + 10000*d5 + 1000*d4 + 100*d3 + 10*d2 + d1);
                    }
                }
            }
        }
    }
}
int main()
{
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    fin >> a >> b;
    makePalindromes();
    sort(palindromes.begin(),palindromes.end());
    for (int i = 0; i<=palindromes.size(); i++){
        if (a<=palindromes[i] && palindromes[i]<=b){
            string num = to_string(palindromes[i]);
            string reversednum = num;
            reverse(reversednum.begin(),reversednum.end());
            if(isPrime(palindromes[i]) && (num==reversednum)){
                fout << palindromes[i] << endl;
            }
        }
        else if(palindromes[i]>b){
            break;
        }
    }
    return 0;
}
