#include<stdio.h>
int d[110][2],a[6];
void div(int n){
	int i;
	for(i=1;i<=n/2;++i) d[i][0]=i,d[i][1]=n-i;
}

bool dfs(int n,int m){
	int i;
	if(n==0) return 1;
	for(i=m-1;i>=0;--i){
		if(dfs(n-a[i],i)) return 1;
	}
	return 0;
}

int main(){
	int i,j,x,y,t,max=0,count;
	scanf("%d",&t);
	while(t--){
		max=0;
		scanf("%d%d",&x,&y);
		a[2]=-y,a[5]=y;
		div(x);
		for(i=1;i<=x/2;++i){
			a[0]=-d[i][0],a[1]=-d[i][1],a[3]=d[i][0],a[4]=d[i][1];
			count=0;
			for(j=x+y;j>=1;--j){
				if(dfs(j,6)) ++count;
			}
			if(count>max) max=count;
		}
		a[2]=-x,a[5]=x;
		div(y);
		for(i=1;i<=y/2;++i){
			a[0]=-d[i][0],a[1]=-d[i][1],a[3]=d[i][0],a[4]=d[i][1];
			count=0;
			for(j=x+y;j>=1;--j){
				if(dfs(j,6)) ++count;
			}
			if(count>max) max=count;
		}
		printf("%d\n",max);
	}
	return 0;
}
