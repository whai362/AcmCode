#include<cstdio>
using namespace std;
int main(){
	int cnt,i,j,t,n,p;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&p);
		cnt=0;
		p=2*n+p;
		for(i=1;i<n;++i){
			for(j=i+1;j<=n;++j){
				printf("%d %d\n",i,j);
				++cnt;
				if(p==cnt) break;
			}
			if(p==cnt) break;
		}
	}
	return 0;
}
