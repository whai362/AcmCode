#include<cstdio>
#include<iostream>
using namespace std;
const int N=55;
bool vis[N];
int f[N];
int getFa(int n){
	if(n!=f[n]) return f[n]=getFa(f[n]);
	return n;
}
__int64 gao(int n){
	__int64 ret=1;
	for(int i=0;i<n;++i){
		ret*=2;
	}
	return ret;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;++i){
		f[i]=i;
	}
	int u,v;
	for(int i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		int fu,fv;
		fu=getFa(u);
		fv=getFa(v);
		f[fv]=fu;
	}
	int cnt=0,fa;
	for(int i=1;i<=n;++i){
		fa=getFa(i);
		if(!vis[fa]){
			++cnt;
			vis[fa]=true;
		}
	}
	cout<<gao(n-cnt)<<endl;
	return 0;
}
