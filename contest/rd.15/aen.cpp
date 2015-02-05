#include<cstdio>
using namespace std;
int main(){
	int ans=0,tmp=0,i,j,k,n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	for(i=0;i<=n/a;++i)
	  for(j=0;j<=(n-a*i)/b;++j){
		  if(!((n-a*i-b*j)%c)) tmp=i+j+(n-a*i-b*j)/c;
		  if(tmp>ans) ans=tmp;
	  }
	printf("%d\n",ans);
	return 0;
}
