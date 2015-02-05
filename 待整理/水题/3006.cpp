#include<stdio.h>
bool isPrime(int n){
	int i;
	if(n==2||n==3) return 1;
	else if(n<=1||n%2==0) return 0;
	for(i=3;i*i<=n;i=i+2){
		if(n%i==0) return 0; 
	}
	return 1;
}
int main(){
	int a,d,n,count;
	while(scanf("%d%d%d",&a,&d,&n)!=EOF&&(a||d||n)){
		count=0;
		while(1){
			if(isPrime(a)) ++count;
			if(count==n) break;
			a=a+d;
		}
		printf("%d\n",a);
	}
	return 0;
}
