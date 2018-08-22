#include <cstdio>
#include <algorithm>
using namespace std;

int tides[100];//max number for N is 100
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &tides[i]);
	sort(tides, tides+n);//sort the data from beginning to where it was left of
	if(n%2==0)//if n is even
		for(int i = n/2-1; i >= 0; i--)//loop from half down as low tides only get lower and high tides only get higher
			printf("%d %d ", tides[i], tides[n-i-1]);//print the higher low tide before print lower lower tide and you print lower high tide before printing higher high tide
	else{//if n is odd
		for(int i = n/2; i>= 1; i--)//loop through half except the last item so treating it as if it were even
			printf("%d %d ", tides[i], tides[n-i]);
		printf("%d", tides[0]);//print lowest tide
	}

}
