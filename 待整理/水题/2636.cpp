#include<stdio.h>
int main(){
	int a,i,n,m,sum;
	scanf("%d",&n);
	while(n--){
		sum=0;
		scanf("%d",&m);
		for(i=0;i<m;++i) scanf("%d",&a),sum=sum+a;
		sum=sum-m+1;
		printf("%d\n",sum);
	}
	return 0;
}
