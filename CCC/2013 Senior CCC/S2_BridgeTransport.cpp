#include <iostream>
#include <deque>
using namespace std;
int W;
int N;
deque<int> railcars;
int workingNum;
bool good(){
    int sum = 0;
    for(int i = 0; i<railcars.size(); i++){
        sum+= railcars[i];
    }
    if(sum>W){
        return false;
    }
    return true;

}
int main()
{
    cin >> W;
    cin >> N;
    int i;
    for(i = 0; i<N; i++){
        int cartW;
        cin >> cartW;
        railcars.push_back(cartW);
        if (railcars.size()>4){
            railcars.pop_front();
        }
        if(!good()){
            break;
        }
        else{
            workingNum++;
        }
    }
    for(int j = 0; j<N-i; j++){
        int a;
        cin >> a;
    }
    cout << workingNum << endl;
    return 0;
}
