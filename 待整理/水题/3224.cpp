#include<stdio.h>
int main(){
	int a,i,j,max,tmp,n,winner;
	scanf("%d",&n);
	max=0;
	for(i=1;i<=n;++i){
	  tmp=0;
	  for(j=0;j<n;++j){
		  scanf("%d",&a);
		  if(a==3) ++tmp;
	  }
	  if(tmp>max) max=tmp,winner=i;
	}
	printf("%d\n",winner);
}
