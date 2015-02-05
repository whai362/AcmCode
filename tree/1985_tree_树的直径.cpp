#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n,m;
struct Data{
	int to,cost;
	Data(){}
	Data(int t,int c){
		to=t;
		cost=c;
	}
};
vector<Data> _map[N];
int d1[N],d2[N];
void dfs(int u,int fa,int dis,int *d){
	for(int i=0;i<_map[u].size();++i){
		Data ch=_map[u][i];
		if(ch.to!=fa) dfs(ch.to,u,d[ch.to]=dis+ch.cost,d);
	}
}
void gao(){
	int i,maxi;
	dfs(1,0,d1[1]=0,d1);
	for(maxi=1,i=2;i<=n;++i)
		if(d1[i]>d1[maxi]) maxi=i;
	dfs(maxi,0,d2[maxi]=0,d2);
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,d2[i]);
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int u,v,c;
		char dir[5];
		scanf("%d%d%d%s",&u,&v,&c,dir);
		_map[u].push_back(Data(v,c));
		_map[v].push_back(Data(u,c));
	}
	gao();
}
