#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int cnt=0,i,j,n,x[205],y[205];
	bool count[205][4];
	scanf("%d",&n);
	for(i=0;i<n;++i)
	  scanf("%d%d",&x[i],&y[i]);
	memset(count,0,sizeof(count));
	for(i=0;i<n-1;++i)
	  for(j=i+1;j<n;++j){
		  if(y[i]==y[j] && x[i]<x[j]) count[i][0]=1,count[j][1]=1;
		  else if(y[i]==y[j] && x[i]>x[j]) count[i][1]=1,count[j][0]=1;
		  else if(x[i]==x[j] && y[i]<y[j]) count[i][2]=1,count[j][3]=1;
		  else if(x[i]==x[j] && y[i]>y[j]) count[i][3]=1,count[j][2]=1;
	  }
	for(i=0;i<n;++i)
	  if(count[i][0]&&count[i][1]&&count[i][2]&&count[i][3]) ++cnt;
	printf("%d\n",cnt);
	return 0;
}
