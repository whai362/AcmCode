#include<stdio.h>
int main(){
	long long n,tmp,count=0;
	while(scanf("%lld",&n)!=EOF){
		//if(n==2147483641){
		//	printf("%lld\n",713987124);
		//	continue;
		//}
		count=0;
		tmp=n+1;
		while(tmp!=1){
			if(tmp%2==0) tmp=tmp>>1;
			else tmp=((tmp+1)>>1)+n;
			++count;	
		}
		printf("%lld\n",count+1);
	}
	return 0;
}
