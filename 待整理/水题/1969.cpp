#include<stdio.h>
#include<math.h>
int main(){
	int n,sum,tmp;
	while(scanf("%d",&n)!=EOF){
		tmp=sqrt(2*n);
		sum=(1+tmp)*tmp/2;
		while(sum<n){
			++tmp;
			sum=(1+tmp)*tmp/2;
		}
		printf("TERM %d IS ",n);
		if(tmp%2==0){
			if(sum==n) printf("%d/1\n",tmp);
			else printf("%d/%d\n",tmp-(sum-n),sum-n+1);
		}
		else{
			if(sum==n) printf("1/%d\n",tmp);
			else printf("%d/%d\n",sum-n+1,tmp-(sum-n));
		}
	}
	return 0;
}
