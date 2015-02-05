#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int a[N],b;
int count(int n){
	int cnt=0;
	while(n){
		if(n&1) ++cnt;
		n>>=1;
	}
	return cnt;
}
int f(int n1,int n2){
	return n1^n2;
}
int main(){
	int m,n,T;
	scanf("%d",&T);
	while(T--){
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+m);
	int _min,ans;
	for(int i=0;i<n;++i){
		scanf("%d",&b);
		_min=0x3f3f3f3f;
		for(int j=0;j<m;++j){
			int tmp=count(f(a[j],b));
			if(tmp<_min){
				_min=tmp;
				ans=a[j];
			}
		}
		printf("%d\n",ans);
	}
	}
	return 0;
}
