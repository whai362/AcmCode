#include<cstdio>
using namespace std;
bool hash[1001][1001];
int main(){
	int count=0,i,j,m,n;
	scanf("%d%d",&n,&m);
	for(i=0;i<=1000;++i)
	  for(j=0;j<=1000;++j){
		  if(i*i+j==n && i+j*j==m){
			  if(!hash[i][j]){
				  ++count;
				  hash[i][j]=1;
			  }
		  }
	  }
	printf("%d\n",count);
	return 0;
}
