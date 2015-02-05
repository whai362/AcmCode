#include<stdio.h>
long long c(int m,int n){
	 int i; 
     double r=1;
	 m=m<n-m? m:n-m;
	 for(i=0;i<m;++i){
		 r=r*(n-i);
		 r=r/(i+1);
	 }
     return r;      
}
int main(){
	int m,n;
	double ans;
	while(scanf("%d%d",&n,&m)&&(n||m)){
		ans=c(m,n);
		printf("%d things taken %d at a time is %0.lf exactly.\n",n,m,ans);
	}
	return 0;
}

