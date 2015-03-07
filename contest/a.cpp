#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=1e5+5;
int a[N];
int main(){
	int T;
	int n,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int p=0,q=0;
		//n==1
		LL ans=0;
		while(p<n){
			LL lim=(LL)a[p]+k;
			while(q+1<n && a[q+1]<=lim){
				++q;
			}
			ans=ans+(q-p);
			++p;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
