#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
	int i,n,w[105];
	double min;
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d",&w[i]);
	sort(w,w+n);
	min=w[n-1];
	for(i=n-2;i>=0;--i) min=2*sqrt(min*w[i]);
	printf("%.3f\n",min);
	return 0;
}
