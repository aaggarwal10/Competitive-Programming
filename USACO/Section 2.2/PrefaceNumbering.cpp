/*
ID: anish.51
LANG: C++
TASK: preface
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
vector<string> keys;
map<string,int> counters;
string to_roman(int value)
{
  struct romandata_t { int value; char const* numeral; };
  static romandata_t const romandata[] =
     { 1000, "M",
        900, "CM",
        500, "D",
        400, "CD",
        100, "C",
         90, "XC",
         50, "L",
         40, "XL",
         10, "X",
          9, "IX",
          5, "V",
          4, "IV",
          1, "I",
          0, NULL }; // end marker

  std::string result;
  for (romandata_t const* current = romandata; current->value > 0; ++current)
  {
    while (value >= current->value)
    {
      result += current->numeral;
      value  -= current->value;
    }
  }
  return result;
}
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}
int romanToDecimal(string str)
{
    // Initialize result
    int res = 0;

    // Traverse given input
    for (int i=0; i<str.length(); i++)
    {
        // Getting value of symbol s[i]
        int s1 = value(str[i]);

        if (i+1 < str.length())
        {
            // Getting value of symbol s[i+1]
            int s2 = value(str[i+1]);

            // Comparing both values
            if (s1 >= s2)
            {
                // Value of current symbol is greater
                // or equal to the next symbol
                res = res + s1;
            }
            else
            {
                res = res + s2 - s1;
                i++; // Value of current symbol is
                     // less than the next symbol
            }
        }
        else
        {
            res = res + s1;
            i++;
        }
    }
    return res;
}
int N;
int main()
{
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    fin >> N;
    string Nbin = to_roman(N);
    for(int i = 1; i<=N; i++){
        string bin = to_roman(i);
        for(int i = 0; i<bin.length(); i++){
            if (counters.find(string(1,bin[i]))!=counters.end()){
                counters[string(1,bin[i])]+=1;
            }
            else{
               counters[string(1,bin[i])]=1;
               keys.push_back(string(1,bin[i]));
            }
        }
    }
    for(int i = 0; i<keys.size(); i++){
        fout << keys[i] <<" "<< counters[keys[i]]<< endl;
    }
}
