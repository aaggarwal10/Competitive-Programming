#include <iostream>
#include <vector>
using namespace std;
vector<int> mountainCarts;
vector<int> branchCarts;
int testCases;
int nextCart;
int main()
{
    cin >> testCases;

    for (int i = 0; i<testCases; i++){

        mountainCarts.clear();
        branchCarts.clear();
        branchCarts.push_back(0);
        nextCart=1;
        bool works = true;
        int cartsNum;

        cin >> cartsNum;
        for (int n = 0; n < cartsNum; n++){
            int cart;
            cin >> cart;
            mountainCarts.push_back(cart);
        }
        while(nextCart<=cartsNum){
            if (mountainCarts.empty() && branchCarts.back()!=nextCart){
                works = false;
                break;
            }
            else if (mountainCarts.back()!=nextCart && branchCarts.back()!=nextCart){
                branchCarts.push_back(mountainCarts.back());
                mountainCarts.pop_back();
            }
            else if(mountainCarts.back()==nextCart){
                mountainCarts.pop_back();
                nextCart++;
            }
            else if(branchCarts.back()==nextCart){
                branchCarts.pop_back();
                nextCart++;
            }
        }
        if (works){
            cout << "Y\n";
        }
        else{
            cout << "N\n";
        }
    }

    return 0;
}
