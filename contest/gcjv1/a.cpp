#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int N=1005;
LL m[N];
int n;
LL gao1(){
	LL ret=0;
	for(int i=1;i<n;++i){
		if(m[i]<m[i-1])
			ret+=m[i-1]-m[i];
	}
	return ret;
}
LL ok(int x){
	LL ret=0;
	for(int i=0;i<n-1;++i){
		if(m[i]-x>m[i+1]) return -1;
		if(m[i]-x>0) ret+=x;
		else ret+=m[i];
	}
	return ret;
}
LL gao2(){
	int l=0,r=100005;
	int mid=(l+r)>>1;
	while(l!=r){
		if(ok(mid)!=-1){
			r=mid;
		}
		else{
			l=mid+1;
		}
		//cout<<l<<' '<<r<<endl;
		mid=(l+r)>>1;
	}
	LL ret=ok(l);
	return ret;
}
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%I64d",&m[i]);
		}
		LL ans1=gao1();
		//cout<<ans1<<endl;
		LL ans2=gao2();
		printf("Case #%d: %I64d %I64d\n",++cas,ans1,ans2);
	}
	return 0;
}
