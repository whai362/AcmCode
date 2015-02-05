#include <iostream>
#include <cstring>
#include <cstdio>
#define LL __int64
using namespace std;

int main(){
	int cases;
	LL n,x,y,z,t,sum;
	scanf("%d",&cases);
	for (int cas=1;cas<=cases;cas++){
		LL ans=0;
		scanf("%I64d%I64d%I64d%I64d%I64d",&n,&x,&y,&z,&t);
		for (int i=0;i<=n;i++){
			for (int j=0;i+j<=n;j++){
				int k=n-i-j;
				sum=(j-1)*j/2*(t+i*z);
				//printf("%I64d\n",sum);
				sum+=(t+i*z)*k*x;
				printf("%d %d %d %I64d\n",i,j,k,sum);
				ans=max(ans,sum);
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

