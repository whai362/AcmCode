#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define PB push_back
const int N=100005;
vector<int> G[N];
int a[N];
void init(int n){
	for(int i=1;i<=n;++i)
		G[i].clear();
	memset(a,0,sizeof(a));
}
int cal(int x,int v){
	int cnt=0;
	for(int i=0;i<G[x].size();++i){
		int ch=G[x][i];
		if(a[ch]==v) ++cnt;
	}
	return G[x].size()-cnt+1;
}
void update(int x,int y,int &ans){
	int pre=a[x];
	a[x]=y;
	int old=cal(x,pre);
	int neww=cal(x,y);
	ans+=neww-old;
	return ;
}
int cas=0;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		init(n);
		int u,v;
		for(int i=0;i<n-1;++i){
			scanf("%d%d",&u,&v);
			G[u].PB(v);
			G[v].PB(u);
		}
		int q;
		scanf("%d",&q);
		int ans=1;
		printf("Case #%d:\n",++cas);
		for(int i=0;i<q;++i){
			int op;
			scanf("%d",&op);
			if(op==1){
				printf("%d\n",ans);
			}
			else{
				int x,y;
				scanf("%d%d",&x,&y);
				update(x,y,ans);
			}
		}
	}
	return 0;
}
