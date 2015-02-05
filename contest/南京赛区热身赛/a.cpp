#include<stdio.h>
int main(){
	int i,flag,n,t;
	int a[51],b[51];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		flag=0;
		for(i=0;i<n;++i)
		  scanf("%d%d",&a[i],&b[i]);
		for(i=1;i<n;++i)
		  if(a[i]<=b[i-1]) flag=1;
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
