#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int i,j,n,a[4][4],tmp1,tmp2;
	scanf("%d",&n);
	for(i=0;i<4;++i)
	  for(j=0;j<4;++j)
		scanf("%d",&a[i][j]);
	for(i=0;i<4;++i){
		tmp1=min(a[i][0],a[i][1]);
		tmp2=min(a[i][2],a[i][3]);
		if(tmp1+tmp2<=n){
			printf("%d %d %d\n",i+1,tmp1,n-tmp1);
			break;
		}
	}
	if(i==4) printf("-1\n");
	return 0;
}
