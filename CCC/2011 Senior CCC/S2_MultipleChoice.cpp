#include <iostream>

using namespace std;

char studentsAnswers[10001];
int N,correct=0;
char correctAns;

int main()
{
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> studentsAnswers[i];
    }
    for(int i = 0; i<N; i++){
        cin >> correctAns;
        if(studentsAnswers[i] == correctAns){
            correct++;
        }
    }
    cout << correct << endl;
    return 0;
}
