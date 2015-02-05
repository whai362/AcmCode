#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define eps 1e-8
int main(){
	int a,b,c,i,j,k,Min,n,tmp1,tmp2,tmp3;
	while(~scanf("%d",&n)){
		Min=0x3f3f3f3f;
		tmp1=(int)(pow(n+0.0,1.0/3.0)+eps);
		for(i=1;i<=tmp1;++i){
			if(!(n%i)){
				tmp2=(int)(pow(n/i+0.0,1.0/2.0)+eps);
				for(j=1;j<=tmp2;++j){
					if(!((n/i)%j)){
						k=n/i/j;
						tmp3=(i*j+i*k+j*k)*2;
						if(tmp3<Min){
							Min=tmp3;
							a=i,b=j,c=k;
						}
					}
				}
			}
		}
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}
