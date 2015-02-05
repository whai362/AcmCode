#include<stdio.h>
int deal(int n,int r){
	int sum=0;
	while(n){
		sum=sum+n%r;
		n=n/r;
	}
	return sum;
}
int main(){
	int i,sum1,sum2,sum3;
	for(i=2992;i<10000;++i){
		sum1=deal(i,10);
		sum2=deal(i,12);
		if(sum1==sum2){
			sum3=deal(i,16);
			if(sum1==sum3) printf("%d\n",i);
		}
		continue;
	}
	return 0;
}
