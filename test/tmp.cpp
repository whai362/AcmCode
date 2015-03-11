#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef __int64 ll;  
const ll MOD=2015LL;  
const int MAXN=1000001;
int T,n,k;
ll ans,f[MAXN]={1LL};
ll Pow(ll a, int n)  
{  
   ll ans = 1LL;  
   while (n)  
   {  
       if (n & 1) 
		   ans=(ans*a)%MOD;
       a=(a*a)%MOD;
       n>>=1;
   }
   return ans;
}  
int main()  
{
   for (int i=1;i<MAXN;++i)  
       f[i]=(f[i-1]*i)%MOD;
   scanf("%d",&T);  
   while (T--)
   {
	   scanf("%d%d",&n,&k);  
       printf("%I64d\n",f[k]*((Pow(k+1,n-k)-Pow(k,n-k)+MOD)%MOD)%MOD);  
   }  
   return 0;
}
