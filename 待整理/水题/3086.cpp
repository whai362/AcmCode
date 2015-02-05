#include<stdio.h>
int T[1010];
int t(int n){
	int i,sum=0;
	if(n==1) return 1;
	if(T[n]) return T[n];
	return t(n-1)+n;
}
int main(){
	int i,m,n,w,cas=0;
	scanf("%d",&m);
	while(m--){
		w=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i) w=w+i*t(i+1);
		printf("%d %d %d\n",++cas,n,w);
	}
	return 0;
}
