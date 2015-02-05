#include<stdio.h>
#include<string.h>
using namespace std;
bool hash[2600005];
int a[500005];
int main(){
	int i,n;
	a[0]=0;
	for(i=1;i<=500000;++i){
		a[i]=a[i-1]-i;
		if(a[i]<=0||hash[a[i]]) a[i]=a[i-1]+i;
		if(a[i]>0) hash[a[i]]=1;
	}
	while(scanf("%d",&n)&&n!=-1) printf("%d\n",a[n]);
	return 0;
}
