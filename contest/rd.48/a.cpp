#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int cnt=0,i,j,ca,a,b,n,ans[100005];
	scanf("%d%d%d",&a,&b,&n);
	ca=a;
	j=0;
	for(i=0;i<n;++i){
		a=a*10+j;
		for(j=0;j<=9;++j)
		    if((a+j)%b==0) break;
		if(j==10){
			printf("-1\n");
			return 0;
		}
		else ans[cnt++]=j;
	}
	printf("%d",ca);
	for(i=0;i<cnt;++i)
	  printf("%d",ans[i]);
	printf("\n");
	return 0;
}
