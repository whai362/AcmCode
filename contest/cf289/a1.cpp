#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define LL __int64
LL a[15][15];
int main(){
	int n;
	for(int i=1;i<15;++i){
		a[1][i]=a[i][1]=1;
	}
	for(int i=2;i<15;++i){
		for(int j=2;j<15;++j){
			a[i][j]=a[i-1][j]+a[i][j-1];
		}
	}
	LL ans[15];
	LL _max=0;
	for(int i=1;i<15;++i){
		_max=0;
		for(int j=1;j<=i;++j){
			for(int k=1;k<=i;++k){
				_max=max(a[i][j],_max);
			}
		}
		ans[i]=_max;
	}
	scanf("%d",&n);
	printf("%I64d\n",ans[n]);
	return 0;
}
