#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
#define N 1000005
#define MOD 1000000007
long long ans[N];
void Egcd(LL a,LL b,LL &x,LL &y){	//扩展欧几里德
	if(b==0){
		x=1;
		y=0;
		return ;  
	}
	Egcd(b,a%b,x,y);  
	LL tmp=x;
	x=y;
	y=tmp-a/b*y;  
}
int main(){
	int cas=0,n;
	int i;
	ans[0] = 0, ans[1] = 1;  
	for(i=2;i<=N;++i){
		LL x,y;
		Egcd(i+1,MOD,x,y);  //求i+1的乘法逆元x
		ans[i]=ans[i-1]*(4*i-2)%MOD*(x%MOD+MOD)%MOD;  
	}
	while(scanf("%d",&n) && n!=-1){
		printf("%lld\n",ans[n]);
	}
	return 0;
}
