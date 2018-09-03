#include <iostream>

using namespace std;
int radius;
int cache[25001]={0};
int findPennies(int r){
    if(cache[r]){
        return cache[r];
    }

    int numPennies = 0;
    for(int x = 1; x<=r; x++){
        for(int y = 1; y<=r; y++){
            if((x*x+y*y)<=r*r){
                numPennies+=1;
            }
        }
    }
    numPennies*=4;
    numPennies+=4*r;
    numPennies+=1;
    cache[r] = numPennies;
    return cache[r];
}
int main()
{
    while (1){
        cin>>radius;
        if(radius){
            cout << findPennies(radius) << endl;
        }
        else{
            break;
        }
    }
    return 0;
}
