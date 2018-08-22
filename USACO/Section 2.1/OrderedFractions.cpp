/*
ID: anish.51
LANG: C++
TASK: frac1
*/
#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;
int N;
map<float,string> fractions;
map<float,string>::iterator it;
struct Current_fraction{
    int n;
    int d;
};
Current_fraction curfraction;
void reduce_fraction (int numerator, int denominator)
{
        for (int i = denominator * numerator; i > 1; i--) {
                if ((denominator % i == 0) && (numerator % i == 0)) {
                    denominator /= i;
                    numerator /= i;
                }
        }
        curfraction.n = numerator;
        curfraction.d = denominator;
}
int main()
{
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    fin >> N;
    fractions[0.0] = "0/1";
    fractions[1.0] = "1/1";
    for (int denominator = 2; denominator <= N; denominator++){
        for (int numerator = 1; numerator < denominator; numerator++){
            reduce_fraction(numerator,denominator);
            fractions[((float)curfraction.n)/curfraction.d] = to_string(curfraction.n)+"/" + to_string(curfraction.d);
            //break;
        }
    }
    for(it = fractions.begin(); it!= fractions.end(); it++){
        fout << it->second << endl;
    }
    return 0;
}
