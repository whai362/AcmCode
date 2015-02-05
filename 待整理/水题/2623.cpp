#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[250005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	if(n & 1)
		printf("%d.0\n",a[n>>1]);
	else
		printf("%.1lf\n",((double)a[n>>1]+(double)a[(n>>1)-1])/2);
	return 0;
}
