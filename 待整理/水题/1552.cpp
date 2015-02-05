#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[200],num[200];
int main(){
	int i,n,m=0,count=0;
	while(scanf("%d",&n)&&n!=-1){
		if(n==0){
			sort(num,num+m);
			for(i=0;i<m;++i){
				if(a[num[i]]) ++count;
				a[2*num[i]]=1;
			}
			printf("%d\n",count);
			m=0,count=0;
			memset(a,0,sizeof(a));
		}
		else num[m++]=n;
	}
	return 0;
}
