#include<cstdio>
#include<iostream>
using namespace std;
int d[100005];
int main(){
	int add=0,i,m,n,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&d[i]);
	}
	for(i=0;i<m;++i){
		scanf("%d%d",&x,&y);
		if(x==1){
			scanf("%d",&z);
			d[y]=z-add;
		}
		else if(x==2) add+=y;
		else
		  printf("%d\n",d[y]+add);
	}
	return 0;
}
