#include<stdio.h>
#include<string.h>
#define N 100000
int main(){
	int i,j,n,temp,flag=0,a[N],y[N],p[N],t[N];
	while(scanf("%d",&n)!=EOF){
		flag=0;
		memset(p,0,sizeof(p));
		memset(t,0,sizeof(t));
		for(i=0;i<n-1;++i) scanf("%d",&a[i]);
		for(i=0;i<n-1;++i) scanf("%d",&y[i]);
		for(i=0;i<n-1;++i){
			if(a[i]==1){
				if(y[i]!=1){
					printf("%d\n",-1);
					break;
				}
				else p[i]=0,t[i]=1; 
			}
			else{
				temp=a[i];
				++t[i];
				if(temp==y[i]) p[i]=t[i];
				while(temp!=1){				
					temp=temp*a[i]%n;
					++t[i];
					if(temp==y[i]){
						if(temp==1) p[i]=0;
						else p[i]=t[i];
					}
				}
			}
		}
		for(i=p[1];!flag;i=i+t[1]){
			flag=1;
			for(j=0;j<n-1;++j){
				if(i%t[j]!=p[j]){
					flag=0;
					break;
				}
			}
		}
		printf("%d\n",i-t[1]);
	}
	return 0;
}
