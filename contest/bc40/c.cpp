#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=1e5+5;
LL f[N],ny[N];
int cnt[N];
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}

void predo(int n,int MOD){
	f[0]=1;
	ny[0]=inv(1,MOD);
	for(int i=1;i<=n;++i){
		int tmp=i;
		while(tmp%MOD==0) tmp/=MOD;
		f[i]=f[i-1]*tmp%MOD;
		ny[i]=inv(f[i],MOD);
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=2;i<=n;++i)
		for(int j=i/MOD;j>0;j/=MOD)
			cnt[i]+=j;
}
LL C(int n,int k,int MOD){
	if(k>n) return 0;
	int num=cnt[n]-cnt[k]-cnt[n-k];
	if(num) return 0;
	return f[n]*ny[k]%MOD*ny[n-k]%MOD;
}
LL cal(int l,int r,int k,int MOD){
	if(l>r) return 0;
	return (C(r+1,k+1,MOD)-C(l,k+1,MOD)+MOD)%MOD;
}
void gao(int x1,int y1,int x2,int y2,int MOD){
	LL ans=0;
	for(int i=y1;i<=y2;++i){
		int l=max(i,x1);
		int r=x2;
		//cout<<l<<' '<<r<<' '<<i<<' ';
		ans=(ans+cal(l,r,i,MOD))%MOD;
		//cout<<ans<<endl;
	}
	printf("%I64d\n",ans);
}
int main(){
	int x1,y1,x2,y2,p;
	while(scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&p)!=EOF){
		predo(max(x2,y2)+2,p);
		gao(x1,y1,x2,y2,p);
	}
	return 0;
}
