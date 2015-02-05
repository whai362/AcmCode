#include<cstdio>
#include<algorithm>
using namespace std;
bool vis[300];
int main(){
	int i,j,n,k,tmp,peak=0,y[300],cy[300];
	scanf("%d%d",&n,&k);
	tmp=2*n+1;
	for(i=0;i<tmp;++i){
		scanf("%d",&y[i]);
		cy[i]=y[i];
	}
	sort(cy,cy+tmp);
	for(j=tmp-1;j>=0;--j){
		for(i=0;i<tmp && k;++i){
			if(y[i]==cy[j] && k && !vis[i]){
				if((i==0 && y[i]-1>y[i+1]) || (i==tmp-1 && y[i]-1>y[i-1]) || (y[i]-1>y[i-1] && y[i]-1>y[i+1])){
					--y[i];
					--k;
					vis[i]=1;
				}
			}
			if(!k) break;
		}
	}
	printf("%d",y[0]);
	for(i=1;i<tmp;++i) printf(" %d",y[i]);
	printf("\n");
	return 0;
}
