int N;
int countS=0, countT=0;
using namespace std;

int main()
{
    cin >> N;
    cin.ignore();
    for(int i = 0; i<N; i++){
        string S;
        getline(cin,S);
        for(char c: S){
            if(c=='S'||c=='s'){
                countS++;
            }
            else if(c=='T' || c=='t'){
                countT++;
            }
        }
    }
    if(countT>countS){
        cout << "English" << endl;
    }
    else{
        cout << "French" << endl;
    }

    return 0;
}
