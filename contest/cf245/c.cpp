#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+5;
int s1[N],s2[N],vis[N];
vector<int> ans,tree[N];
void dfs(int pa,int dep,int f1,int f2){
	vis[pa]=1;
	if(dep%2==0){
		if(s1[pa]^f1!=s2[pa]){
			ans.push_back(pa);
			f1^=1;
		}
	}
	else{
		if(s1[pa]^f2!=s2[pa]){
			ans.push_back(pa);
			f2^=1;
		}
	}
	int sz=tree[pa].size();
	for(int i=0;i<sz;++i){
		int ch=tree[pa][i];
		if(!vis[ch])
			dfs(ch,dep+1,f1,f2);
	}
}
int main(){
	int n,u,v,f;
	int i;
	scanf("%d",&n);
	for(i=0;i<n-1;++i){
		scanf("%d%d",&u,&v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for(i=1;i<=n;++i){
		scanf("%d",&s1[i]);
	}
	for(i=1;i<=n;++i){
		scanf("%d",&s2[i]);
	}
	dfs(1,0,0,0);
	//sort(ans.begin(),ans.end());
	int sz=ans.size();
	printf("%d\n",sz);
	for(i=0;i<sz;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}
