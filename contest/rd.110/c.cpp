#include<cstdio>
using namespace std;
int main(){
	int i,n;
	while(scanf("%d",&n) && n){
		int pre=0,now,ans=0;
		for(i=0;i<n;++i){
			scanf("%d",&now);
			if(now>=pre){
				ans+=(now-pre)*6+5;
			}
			else{
				ans+=(pre-now)*4+5;
			}
			pre=now;
		}
		printf("%d\n",ans);
	}
	return 0;
}
