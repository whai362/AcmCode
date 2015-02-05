//whai
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
LL l,r;
LL ans[105],cnt;
void gao(){
	cnt=0;
	int i;
	for(i=61;i>=0;--i){
		LL a1=((1LL<<i) & l)>0?1LL:0LL;
		LL a2=((1LL<<i) & r)>0?1LL:0LL;
		ans[cnt++]=a1;
		if(a1!=a2) break;
	}
	//cout<<i<<endl;
	--i;
	for(;i>=0;--i){
		ans[cnt++]=1;
	}
	LL out=0;
	int cnt1=0;
	int cnt2=0;
	for(int i=0;i<cnt;++i){
		//cout<<ans[i]<<' ';
		out=out*2+ans[i];
		if(ans[i]) ++cnt1;
	}
	//cout<<endl;
	LL tmp=r;
	while(tmp>0){
		if(tmp&1LL) ++cnt2;
		tmp>>=1;	
	}
	if(cnt1>=cnt2){
	printf("%I64d\n",out);
	}
	else printf("%I64d\n",r);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	scanf("%I64d%I64d",&l,&r);
	gao();
	}
	return 0;
}
