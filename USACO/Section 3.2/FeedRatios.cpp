/*
ID: anish.51
PROB: ratios
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;
int goal[3];
int minNumFeeds=301;
int curAmountNeeded[3] = {0};
int feeds[3][3];
int feedWithMult[3][3];
int goalR;
int goalWithMult[3];
ifstream fin ("ratios.in");
ofstream fout ("ratios.out");
void ratioNeeded(int amounts[]){
    for(int i = 0; i<3; i++){
        for(int curI = 0; curI<3; curI++){
            feedWithMult[i][curI] = feeds[i][curI]*amounts[i];
        }
    }
    int sums[3];
    for(int i = 0; i<3; i++){
        sums[i] = feedWithMult[0][i]+feedWithMult[1][i]+feedWithMult[2][i];
    }
    for (int goalAmountNeeded =1; goalAmountNeeded<100; goalAmountNeeded++){
        goalWithMult[0]=goal[0]*goalAmountNeeded;
        goalWithMult[1] = goal[1]*goalAmountNeeded;
        goalWithMult[2] = goal[2]*goalAmountNeeded;
        if(goalWithMult[0] == sums[0] && goalWithMult[1] == sums[1] && goalWithMult[2] == sums[2]){

            minNumFeeds = amounts[0]+amounts[1]+amounts[2];
            curAmountNeeded[0] = amounts[0];
            curAmountNeeded[1] = amounts[1];
            curAmountNeeded[2]= amounts[2];
            goalR = goalAmountNeeded;
            break;
        }
    }
}
int main()
{
    fin >> goal[0] >> goal[1] >> goal[2];
    for (int feedR = 0; feedR<3; feedR++){
        fin >> feeds[feedR][0] >> feeds[feedR][1] >> feeds[feedR][2];
    }
    for(int amount1 = 0; amount1 <100; amount1++){
        for(int amount2 = 0; amount2<100; amount2++){
            for(int amount3 = 0; amount3<100; amount3++){
                if(amount1+amount2+amount3<minNumFeeds){
                    int amounts [3] = {amount1,amount2,amount3};
                    ratioNeeded(amounts);
                }
            }
        }
    }
    if(curAmountNeeded[0]==0&&curAmountNeeded[1]==0 && curAmountNeeded[2]==0){
        fout << "NONE" << endl;
        return 0;
    }
    fout << curAmountNeeded[0] << " " << curAmountNeeded[1] << " " << curAmountNeeded[2] << " " << goalR << endl;
    return 0;

}
