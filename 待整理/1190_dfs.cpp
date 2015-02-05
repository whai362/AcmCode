#include<cstdio>
#include<iostream>
using namespace std;
int ans,n,m,tmp;
int sum_n3(int x){
	return (x+1)*(x+1)*x*x/4 ;
}
void dfs(int v,int floor,int s,int r,int h){
	if(floor==0){
		if(v==0) ans=min(ans,s);
		return ;
	}
	if(s+2*v/r>ans || v<sum_n3(floor)) return ;
	for(int i=r-1;i>=floor;--i){
		if(floor==m)
			s=i*i;
		for(int j=h-1;j>=floor;--j){
			if(v-i*i*j>=0){
				dfs(v-i*i*j,floor-1,s+2*i*j,i,j);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	ans=0x3f3f3f3f;
	dfs(n,m,0,100+1,10000+1);
	if(ans!=0x3f3f3f3f)
		printf("%d\n",ans);
	else
		printf("0\n");
	return 0;
}
