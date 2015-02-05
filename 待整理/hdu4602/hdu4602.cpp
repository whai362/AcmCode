#include<stdio.h>
#include<iostream>
using namespace std;
#define mod 1000000007
long long a_b_Mod_c(long long a, int b, int c){
    long long result = 1;
    int digit[32];
    int i,k;
    i = 0;
    while(b){
        digit[i++] = b%2;
        b >>= 1;
    }
    for(k = i-1; k >= 0; k--)
    {
        result = (result * result) % c;
        if(digit[k] == 1)
        {
            result = (result * a) % c;
        }
    }
    return result;
}

int main(){
	int t,m,n;
	long long tmp,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(m==0||m>n) printf("%d\n",0);
		else if(n==m) printf("%d\n",1);
		else if(n-1==m) printf("%d\n",2);
		else{
			ans=0;
			tmp=(2*a_b_Mod_c(2,n-m-1,mod))%mod;
			ans=ans+tmp;
			tmp=((n-m-1)*a_b_Mod_c(2,n-m-2,mod))%mod;
			ans=(ans+tmp)%mod;
			printf("%d\n",ans);
		}
	}
	return 0;
}

