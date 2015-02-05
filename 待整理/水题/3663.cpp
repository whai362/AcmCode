#include<stdio.h>
#include<algorithm>
using namespace std;
int a[20005];
int main(){
	int i,j,n,s,sum;
	scanf("%d%d",&n,&s);
	sum=n*(n-1)/2;
	for(i=0;i<n;++i) scanf("%d",&a[i]);
	sort(a,a+n);
	i=0,j=n-1;
	while(i<n-1&&j>i){
		if(a[i]+a[j]>s) sum=sum-(j-i),--j;
		else ++i;
	}
	printf("%d\n",sum);
	return 0;
}
