/*
ID: anish.51
PROB: spin
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int speed[5];
int wedgesStart[5][5];
int wedgesExtent[5][5];
int wedgesNum[5];
int lightLine[360] = {0};
int timeCounter = 0;
ifstream fin ("spin.in");
ofstream fout ("spin.out");
int main()
{
    for(int wheel = 0; wheel<5; wheel++){
        int rotSpeed, numW;
        fin >> rotSpeed >> numW;
        speed[wheel] = rotSpeed;
        wedgesNum[wheel] = numW;
        for(int wedge = 0; wedge<numW; wedge++){
            int start,exten;
            fin >> start >> exten;
            wedgesStart[wheel][wedge]=start;
            wedgesExtent[wheel][wedge] = exten;
        }
    }
    while (timeCounter<360){
        memset(lightLine,0,sizeof(lightLine));
        for (int wheel = 0; wheel<5; wheel++){
            for(int wedgeCount = 0; wedgeCount<wedgesNum[wheel];wedgeCount++){
                int startOfWedge = wedgesStart[wheel][wedgeCount] + speed[wheel]*timeCounter;
                int extentOfWedge = wedgesExtent[wheel][wedgeCount];
                for(int degreeAdd = 0; degreeAdd<=extentOfWedge; degreeAdd++){
                    lightLine[(startOfWedge+degreeAdd)%360]+=1;
                }
            }
        }
        for(int i = 0; i<360; i++){
            if(lightLine[i]==5){
                fout << timeCounter << endl;
                return 0;
            }
        }
        timeCounter++;
    }


    fout << "none" << endl;
    return 0;
}
