#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define LL __int64
const int N=100005;
int cnt[N];
LL C(int n,int m){
	if(n<m) return 0;
	LL ret=1;
	for(int i=n;i>n-m;--i)
		ret*=(LL)i;
	for(int i=2;i<=m;++i)
		ret/=i;
	return ret;
}
LL gao(int x,int c){
	LL ret=C(c,4);
	int lim=sqrt(x);
	int flag=0;
	for(int i=2;i<=lim;++i){
		if(x%i==0){
			++flag;
			x/=i;
		}
		if(x%i==0) return 0;
	}
	if(x!=1) ++flag;
	if(flag%2==0) return ret;
	else return -ret;
}
int main(){
	int n,a,_max;
	while(scanf("%d",&n)!=EOF){
		_max=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			_max=max(_max,a);
			++cnt[a];
			int lim=sqrt(a);
			for(int j=2;j<=lim;++j){
				if(a%j==0){
					++cnt[j];
					if(a/j!=j) ++cnt[a/j];
				}
			}
		}
		LL ans=C(n,4);
		for(int i=2;i<=_max;++i){
			if(cnt[i]>=4)
				ans+=gao(i,cnt[i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
