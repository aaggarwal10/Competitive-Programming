/*
ID: anish.51
PROB: shopping
LANG: C++
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

vector<pi> sOffers[100];
int costs[100] = {};
int numOffers, numItems;
int dp[6][6][6][6][6];
int req[6];
int initCosts[6];
map<int,int> productNums;
int MAX = 100000;

struct SPECIAL_OFF{
    int items[6]={};
    int price=0;
};
SPECIAL_OFF offers[110];

SPECIAL_OFF makeOffer(vector<pi> offer, int cost){
    SPECIAL_OFF sOff;
    for(int i = 0; i<offer.size(); i++){
        sOff.items[productNums[offer[i].first]] = offer[i].second;
    }
    sOff.price = cost;
    return sOff;
}

bool OfferValid(vector<pi> offer){
    for(int i = 0; i<offer.size(); i++){
        if(productNums.find(offer[i].first)==productNums.end()){
            return false;
        }
    }
    return true;
}
int main()
{
#ifndef LOCAL
    ifstream cin("shopping.in");
    ofstream cout("shopping.out");
#endif
    memset(dp,127,sizeof(dp));
    cin >> numOffers;
    for(int i = 0; i<numOffers; i++){
        int numPairs;
        cin >> numPairs;
        for(int j = 0; j<numPairs; j++){
            int pCode, quantity;
            cin >> pCode >> quantity;
            sOffers[i].push_back(make_pair(pCode, quantity));
        }
        cin >> costs[i];
    }
    cin >> numItems;
    int numO = 0;
    for(int i = 0; i<numItems; i++){
        int pCode, quantity, cost;
        cin >> pCode >> quantity >> cost;
        req[i] = quantity;
        productNums[pCode] = i;
        initCosts[i] = cost;
        offers[numO].items[i] = 1;
        offers[numO].price = cost;
        numO++;

    }

    for(int n = 0; n<numOffers; n++){
        if(OfferValid(sOffers[n])){
            offers[numO] = makeOffer(sOffers[n],costs[n]);
            numO++;
        }
    }

    dp[0][0][0][0][0] = 0;

    for(int x1 = 0; x1<6; x1++){
        for(int x2 = 0; x2<6; x2++){
            for(int x3 = 0; x3<6; x3++){
                for(int x4 = 0; x4<6; x4++){
                    for(int x5=0; x5<6; x5++){
                        for(int n = 0; n<numO; n++){
                            int n1 = offers[n].items[0];
                            int n2 = offers[n].items[1];
                            int n3 = offers[n].items[2];
                            int n4 = offers[n].items[3];
                            int n5 = offers[n].items[4];
                            if(x1-n1>=0 && x2-n2>=0 && x3-n3>=0 && x4-n4>=0 && x5-n5>=0){
                                dp[x1][x2][x3][x4][x5] = min(dp[x1][x2][x3][x4][x5],dp[x1-n1][x2-n2][x3-n3][x4-n4][x5-n5]+offers[n].price);
                            }
                        }
                    }
                }
            }
        }
    }


    cout << dp[req[0]][req[1]][req[2]][req[3]][req[4]] << endl;
    return 0;
}
