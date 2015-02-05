#include<stdio.h>
int a[100000];
int lis(int a[],int n){
	int left,right,mid,i,len=1,b[100000];
	b[1]=a[1];
	for(i=2;i<=n;++i){
		left=1,right=len;
		while(left<=right){
			mid=(left+right)/2;
			if(b[mid]>=a[i]) left=mid+1;
			else right=mid-1;
		}
		b[left]=a[i];
		if(left>len) ++len;
	}
	return len;
}
int main(){
	int cas=0,i,flag,m,n;
	while(1){
		flag=0,n=0;
		while(scanf("%d",&m)){
			if(m==-1){
				if(n==0) flag=1;
				break;
			}
			else a[++n]=m;
		}
		if(flag) break;
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",++cas,lis(a,n));
	}
	return 0;
}
