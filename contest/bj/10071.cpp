#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define Maxn 100050;

int cnt[100050];
bool vis[100050];
int main(){
	int cases,n,x1,x2;
	scanf("%d",&cases);
	for (int cas=1;cas<=cases;cas++){
		int x,s;
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		memset(vis,false,sizeof(vis));
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			s=10000-(100-x)*(100-x);
			vis[x]=true;
			cnt[s]++;
		}
		int Max=0;
		for (int i=0;i<=10000;i++){
			if (cnt[Max]<cnt[i]) Max=i;
		}
		bool flag=true;
		for (int i=0;i<=10000;i++){
			x1=100-sqrt(10000-s);
			x2=100+sqrt(10000-s);
			if (cnt[Max]==cnt[i]){
				if (x1!=x2&&vis[x1]&&vis[x2]) flag=false;
			}
		}
		printf("Case #%d:\n",cas);
		if (!flag) puts("Bad Mushroom");
		else{
			for (int i=0;i<=10000;i++){
				x1=100-sqrt(10000-s);
				x2=100+sqrt(10000-s);
				if (cnt[Max]==cnt[i]){
					if (Max!=i){
						printf("%d ",i);
					}
					else printf("%d\n",i);
				}				
			}
		}
	}
	return 0;
}

