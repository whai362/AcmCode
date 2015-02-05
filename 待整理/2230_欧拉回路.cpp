#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int N=100005,	//n要大一点，因为一个点不止经过一次
		  M=50005;
struct Data{
	int v,id;
	Data(){}
	Data(int _v,int _id){
		v=_v;
		id=_id;
	}
};
int cnt;
int ans[N];
bool vis[2*M];
vector<Data> _map[N];
void dfs(int rt){
	int sz=_map[rt].size();
	for(int i=0;i<sz;++i){
		if(!vis[_map[rt][i].id]){
			vis[_map[rt][i].id]=true;
			dfs(_map[rt][i].v);
		}
	}
	//printf("%d\n",rt);
	ans[cnt++]=rt;
}
int main(){
	int n,m,u,v,e=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		_map[u].push_back(Data(v,e++));
		_map[v].push_back(Data(u,e++));
	}
	dfs(1);
	for(int i=cnt-1;i>=0;--i){
		printf("%d\n",ans[i]);
	}
	return 0;
}
