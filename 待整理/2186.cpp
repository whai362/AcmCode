#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=10005;
int f[N],p[N];
void find(int n){
	if(n!=f[n]){
		++p[f[n]];
		find(f[n]);
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(p,0,sizeof(p));
	for(int i=0;i<=n;++i){
		f[i]=i;
	}
	for(int i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		f[u]=v;
	}
	for(int i=1;i<=n;++i){
		find(i);
	}
	for(int i=1;i<=n;++i){
		cout<<p[i]<<endl;
	}
	return 0;
}
