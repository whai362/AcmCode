#include<cstdio>
using namespace std;
int t[1005];
int main(){
	int i,j,flag=0,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	  scanf("%d",&t[i]);
	for(i=0;i<=1000;++i){
		for(j=1;j<=n;++j){
			if(t[j]==i) t[j]=-1;
		}
		for(j=1;j<=n;++j){
			if((j==n || j==1) && t[j]==-1){
				flag=1;
				break;
			}
			if(t[j]==-1 && t[j+1]==-1){
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	printf("%d\n",i);
	return 0;
}
