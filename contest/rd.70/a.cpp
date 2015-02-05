#include<cstdio>
using namespace std;
int d[101],ans[5];
int main(){
	int i,k,cnt=0;
	scanf("%d",&k);
	for(i=0;i<k;++i){
		scanf("%d",&d[i]);
		if(d[i]==0) ans[0]=1,++cnt;
		else if(d[i]==100) ans[2]=1,++cnt;
		else if(d[i]<10){
			if(!ans[3]) ans[3]=d[i],++cnt;
		}
		else if(d[i]>=10 && d[i]%10==0){
			if(!ans[1]) ans[1]=d[i],++cnt;
		}
	}
	if(!ans[1] && !ans[3]){
		for(i=0;i<k;++i){
			if(d[i]>10 && d[i]%10){
				ans[3]=d[i];
				++cnt;
				break;
			}
		}
	}
	printf("%d\n",cnt);
	if(ans[0]) printf("0 ");
	if(ans[1]) printf("%d ",ans[1]);
	if(ans[2]) printf("100 ");
	if(ans[3]) printf("%d",ans[3]);
	printf("\n");
	return 0;
}
