#include<cstdio>
#include<iostream>
using namespace std;
#define N 30005
int fa[N];
int getFa(int n){
	if(fa[n]!=n){
		return fa[n]=getFa(fa[n]);
	}
	return n;
}
int main(){
	int a,k,n,m,f1,f2;
	int i,j;
	while(scanf("%d%d",&n,&m) && (n || m)){
	for(i=0;i<n;++i){
		fa[i]=i;
	}
	for(i=0;i<m;++i){
		scanf("%d",&k);
		scanf("%d",&a);
		f1=getFa(a);
		for(j=1;j<k;++j){
			scanf("%d",&a);
			f2=getFa(a);
			if(f1!=f2){
				fa[f2]=f1;
			}
		}
	}
	int ans=0,ans_f=getFa(0);
	for(i=0;i<n;++i){
		if(getFa(i)==ans_f)
			++ans;
	}
	printf("%d\n",ans);
	}
	return 0;
}
