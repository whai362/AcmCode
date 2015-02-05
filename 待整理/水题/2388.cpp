#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10010];
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d",&a[i]);
	sort(a,a+n);
	printf("%d\n",a[(n-1)/2]);
	return 0;
}
