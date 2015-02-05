#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int f[30010],s[30010];
int getFather(int x){
	if(f[x]!=x) f[x]=getFather(f[x]);
	return f[x];
}
int main(){
	int count,k,f1,ft,m,n;
	int i;
	while(scanf("%d%d",&n,&m)&&(n||m)){
		count=0;
		for(i=0;i<n;++i) f[i]=i;
		while(m--){
			scanf("%d",&k);
			for(i=0;i<k;++i) scanf("%d",&s[i]);
			sort(s,s+k);
			f1=getFather(s[0]);
			for(i=1;i<k;++i){
				ft=getFather(s[i]);
				if(f1<ft) f[ft]=f1;
				else f[f1]=ft,f1=getFather(s[0]);
			}
		}
		for(i=0;i<n;++i) if(getFather(i)==0) ++count;
		printf("%d\n",count);
	}
	return 0;
}

