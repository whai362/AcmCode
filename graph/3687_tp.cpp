#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define pb push_back
const int N=205;
int n,m;
int ans[N],out[N];
vector<int> mp[N];
void gao(){
	int cnt=0;
	priority_queue< int,vector<int>,less<int> > q;
	for(int i=1;i<=n;++i)
		if(out[i]==0) q.push(i);
	while(!q.empty()){
		int now=q.top();
		q.pop();
		ans[now]=n-(cnt++);
		for(int i=0;i<mp[now].size();++i){
			int ch=mp[now][i];
			--out[ch];
			if(out[ch]==0) q.push(ch);
		}
	}
	if(cnt==n)
		for(int i=1;i<=n;++i)
			printf("%d%c",ans[i],i==n?'\n':' ');
	else puts("-1");

}
void init(){
	for(int i=1;i<=n;++i)
		mp[i].clear();
	memset(out,0,sizeof(out));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&n,&m);
		int u,v;
		for(int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			mp[v].pb(u);
			++out[u];
		}
		gao();
	}
	return 0;
}
