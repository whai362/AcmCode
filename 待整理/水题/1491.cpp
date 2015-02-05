#include<stdio.h>
#include<math.h>
int num[60];
int gcd(int a,int b){
	if(b) return gcd(b,a%b);
	return a;
}
int main(){
	int i,j,count,n;
	double tmp;
	while(scanf("%d",&n)&&n){
		count=0;
		for(i=0;i<n;++i) scanf("%d",&num[i]);
		for(i=0;i<n-1;++i)
		  for(j=i+1;j<n;++j){
			  if(gcd(num[i],num[j])==1) ++count;
		  }
		if(count==0) printf("No estimate for this data set.\n");
		else{
			tmp=(double)count/(n*(n-1)/2);
			tmp=sqrt(6.0/tmp);
			printf("%.6f\n",tmp);
		}
	}
	return 0;
}
