#include<stdio.h>
int main(){
	int a,n,sum;
	while(scanf("%d",&n)&&n){
		sum=0;
		while(n--) scanf("%d",&a),sum=sum+a*a;
		printf("%d\n",sum);
	}
}
