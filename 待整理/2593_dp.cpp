#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005,
	  INF=0x3f3f3f3f;
int a[N],dp0[N],dp1[N];
int gao(int m,int n){
	memset(dp0,0,sizeof(dp0));
	memset(dp1,0,sizeof(dp1));
	int _max;
	for(int i=1;i<=m;++i){
		_max=-INF;
		for(int j=i;j<=n;++j){
			dp0[j]=max(dp0[j-1],dp1[j-1])+a[j];
			dp1[j-1]=_max;
			_max=max(dp0[j],_max);
		}
	}
	return _max;
}
int main(){
	int n;
	while(scanf("%d",&n) && n){
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		printf("%d\n",gao(2,n));
	}
	return 0;
}
