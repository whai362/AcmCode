#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int N=1005;
const LL INF=(1e9+5)*(1e5+5);
LL m[N];
int n,b;
bool ok(LL x){
	LL ret=0;
	for(int i=0;i<b;++i){
		ret+=x/m[i]+1;
	}
	if(ret>=n)
		return true;
	else
		return false;
}
void gao(){
	LL l=0,r=INF;
	LL mid=(l+r)>>1;
	while(l!=r){
		if(ok(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
		//cout<<l<<' '<<r<<endl;
		mid=(l+r)>>1;
	}
	--l;
	//cout<<l<<endl;
	LL yj=0;
	for(int i=0;i<b;++i){
		yj+=l/m[i]+1;
	}
	LL mj=n-yj;
	//cout<<mj<<endl;
	int ans=0;
	for(int i=0;i<b;++i){
		if((l+1)%m[i]==0){
			ans=i+1;
			--mj;
			if(mj==0) break;
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	int cas=0;
	while(T--){
		cin>>b>>n;
		for(int i=0;i<b;++i){
			cin>>m[i];
		}
		printf("Case #%d: ",++cas);
		if(b>=n){
			cout<<(n-1)%b+1<<endl;
		}
		else{
			gao();
		}
	}
	return 0;
}
