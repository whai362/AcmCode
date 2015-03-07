#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
LL deal(int p,LL s,LL x){
	if(s>x) return 0;
	LL ret=1;
	for(int i=1;i<=9;++i){
		if(p%i!=0) continue;
		if(s*10+p/i>x) continue;
		LL tmp=deal(p/i,s*10+p/i,x);
		ret+=tmp;
		//cout<<i<<' '<<tmp<<endl;
		//ret+=gao(p*i,s*10+p*i,x)+1;
	}
	return ret;
}
LL gao(int x){
	LL ret=0;
	for(int i=1;i<=9;++i){
		ret+=deal(i,i,x);
	}
	return ret;
}
int main(){
	int T;
	int l,r;
	//int tt;
	//cin>>tt;
	//cout<<gao(tt)<<endl;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&l,&r);
		LL ans=gao(r)-gao(l-1);
		printf("%I64d\n",ans);
	}
	return 0;
}
