#include<cstdio>
using namespace std;
int hash[1005];
int main(){
	int i,j,n,m,v1,v2;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;++i){
		scanf("%d%d",&v1,&v2);
		hash[v1]=hash[v2]=1;
	}
	for(i=1;i<=n;++i){
		if(!hash[i]) break;
	}
	printf("%d\n",n-1);
	for(j=1;j<=n;++j){
		if(i!=j)
		  printf("%d %d\n",i,j);
	}
	return 0;
}
