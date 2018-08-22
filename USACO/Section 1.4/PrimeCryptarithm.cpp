/*
ID: anish.51
LANG: C++
TASK: crypt1
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int digitsToUse[10];
int N;
int works = 0;
int hasDigits(int num, int numdigits){
    if (num==0){
        return 0;
    }
    while(num){
        if(!digitsToUse[num%10]){
            return 0;
        }
        num/=10;
        numdigits--;
    }
    if (numdigits==0){
        return 1;
    }
    else{
        return 0;
    }
}
int ProperProduct(int multiA, int multiB){
    if (!hasDigits(multiA*multiB,4)||!hasDigits(multiA,3)||!hasDigits(multiB,2)){
        return 0;
    }
    while(multiB){
        if (!hasDigits(multiA*(multiB%10),3)){
            return 0;
        }
        multiB/=10;
    }
    return 1;
}

int main(){
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    fin >> N;
    for (int i = 0; i<10; i++){
        digitsToUse[i] = 0;
    }
    for (int i = 0; i<N; i++){

        int digit;
        fin >> digit;
        digitsToUse[digit]=1;
    }
    for (int multiplicand = 100; multiplicand<1000; multiplicand++){
        for (int multipler = 10; multipler<100; multipler++){
            if (ProperProduct(multiplicand,multipler)){
                works++;
            }
        }
    }

    fout << works << "\n";

    return 0;
}
