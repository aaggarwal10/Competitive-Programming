#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> boxes;
vector <int> package;
int N,M;
const long long MAXV = 8000000001;
int main()
{
    cin >> N;
    for(int i = 0; i<N; i++){
        int w,l,h;
        cin >> w >> l >> h;
        vector<int> box;
        box = {w,l,h};
        sort(box.begin(),box.end());
        boxes.push_back(box);
    }
    cin >> M;
    for(int i = 0; i<M; i++){
        int w,l,h;
        cin >> w >> l >> h;
        package = {w,l,h};
        sort(package.begin(),package.end());
        long long volume = MAXV;
        for(int j = 0; j<N; j++){
            bool works = true;
            for(int k = 0; k<3; k++){
                if(package[k]>boxes[j][k]){
                    works = false;
                    break;
                }
            }
            if (works){
                if(volume > boxes[j][0]*boxes[j][1]*boxes[j][2])
                    volume = boxes[j][0]*boxes[j][1]*boxes[j][2];

            }

        }
        if(volume == MAXV){
            cout << "Item does not fit." << endl;
        }
        else{
            cout << volume << endl;
        }
    }
    return 0;
}
