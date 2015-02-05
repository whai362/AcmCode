#include<cstdio>
#include<iostream>
using namespace std;
const int N=1e5+5;
const long long INF=1e17+5;
int n,m;
long long q;
long long s[N],p[N],a[N];
long long gao(int q){
	int l=0,r=n,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(s[mid]>=q){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	//cout<<l<<' '<<r<<endl;
	long long ans=q*p[l];
	//cout<<ans<<endl;
	//cout<<a[r]<<endl;
	ans=min(ans,a[r]);
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%lld%lld",&s[i],&p[i]);
	}
	for(int i=0;i<n;++i){
		a[i]=s[i]*p[i];
	}
	a[n]=INF;
	for(int i=n-2;i>=0;--i){
		a[i]=min(a[i],a[i+1]);
	}
	/*for(int i=0;i<n;++i)
		cout<<a[i]<<' ';*/
	//cout<<endl;
	for(int i=0;i<m;++i){
		scanf("%lld",&q);
		printf("%lld\n",gao(q));
	}
	}
	return 0;
}

