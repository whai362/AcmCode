#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int i,j,n,tmp,a[3010],ab[3010];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;++i) scanf("%d",&a[i]);
		for(i=0;i<n-1;++i) ab[i]=abs(a[i]-a[i+1]);
		for(i=0;i<n-2;++i)
		  for(j=i+1;j<n-1;++j) if(ab[i]<ab[j]) tmp=ab[i],ab[i]=ab[j],ab[j]=tmp;
		for(i=0;i<n-1;++i) if(ab[i]!=n-1-i) break;
		if(i==n-1) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}

