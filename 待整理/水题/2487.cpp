#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){ return a>b; }
int main(){
	int cas=0,i,m,n,sum,t,a[1005];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=0;i<m;++i) scanf("%d",&a[i]);
		sort(a,a+m,cmp);
		sum=0;
		for(i=0;i<m;++i){
			sum=sum+a[i];
			if(sum>=n) break;
		}
		printf("Scenario #%d:\n",++cas);
		if(i==m) printf("impossible\n\n");
		else printf("%d\n\n",i+1);
	}
	return 0;
}
