#include<stdio.h>
int a[100000][2];
int main(){
	int i,j,t=0,n,m,flag=1,lm=0,sum=0,k,max=0,min=100000;
	scanf("%d",&k);
	while(k--){
	max=0,t=0,lm=0,flag=1,sum=0,min=100000;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		scanf("%d%d",&a[i][0],&a[i][1]);
		if(max<a[i][0]) max=a[i][0];
		if(min>a[i][1]) min=a[i][1];
		sum=sum+a[i][0];
	}
	if(max>m) printf("superman is dead!\n");
	else{
		for(i=0;i<n-1;++i){
			if(sum<=m&&a[i][1]==min){
				flag=0;
				t=t+sum*a[i][1];
				break;
			}
			else if(a[i][1]>=a[i+1][1]) t=t+(a[i][0]-lm)*a[i][1],lm=0;
			else t=t+(m-lm)*a[i][1],lm=m-a[i][0];
			if(a[i][1]==min){
				min=100000;
				for(j=i+1;j<n;++j){
					if(min>a[j][1]) min=a[j][1];
				}
			}
			sum=sum-a[i][0];
		}
		if(flag)t=t+(a[i][0]-lm)*a[i][1],lm=0;
		printf("%d\n",t);
	}
	}
	return 0;
}
