#include<iostream>
#include<cstdio>
using namespace std;
#define N 1000005
#define mod 1000000007
#define LL long long
long long ans[N];
void Egcd (LL a, LL b, LL &x, LL &y)    //扩展欧几里德  
{
	if (b == 0)  
	{  
		x = 1;  
		y = 0;  
		return ;   
	}  
	Egcd (b, a%b, x, y);  
	LL tp = x;  
	x = y;  
	y = tp - a/b*y;  
}

int main(){
	int i;
	ans[0] = 0, ans[1] = 1;  
	for (i = 2; i <= N; i++)  
	{
		LL x, y;
		Egcd (i+1, mod, x, y);  //求i+1的乘法逆元x
		ans[i] = ans[i-1]*(4*i-2)%mod * (x%mod+mod)%mod;  
	}
	int cas=0,n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("Case #%d:\n%lld\n",++cas,ans[n]);
	}
	return 0;
}
