#include<stdio.h>
bool isPrime(int n){
	int i;
	if(n<2) return 0;
	else if(n==2||n==3) return 1;
	else if(n%2==0) return 0;
	else for(i=3;i*i<=n;i=i+2) if(n%i==0) return 0;
	return 1;
}
int main(){
	int i,n;
	while(scanf("%d",&n)&&n){
		for(i=3;i<n;++i){
			if(isPrime(i)&&isPrime(n-i)){
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
		}
	}
	return 0;
}
