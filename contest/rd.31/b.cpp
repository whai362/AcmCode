#include<cstdio>
#include<iostream>
using namespace std;
int a[1005][1005],r[1005],c[1005];
int main(){
	int a1,b1,i,j,n,m,k1,tmp;
	char p[5];
	scanf("%d%d%d",&n,&m,&k1);
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			scanf("%d\n",&a[i][j]);
		}
	}
	for(i=0;i<1005;++i) r[i]=c[i]=i;
	for(i=0;i<k1;++i){
		scanf("%s%d%d",p,&a1,&b1);
		if(p[0]=='c'){
			tmp=c[a1];
			c[a1]=c[b1];
			c[b1]=tmp;
		}
		if(p[0]=='r'){
			tmp=r[a1];
			r[a1]=r[b1];
			r[b1]=tmp;
		}
		if(p[0]=='g')
		  printf("%d\n",a[r[a1]][c[b1]]);
	}
	return 0;
}
