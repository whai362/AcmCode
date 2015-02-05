#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=2000005;
const long long INF=9999999999;
struct data{
	int v;
	long long c;
	data(){}
	data(int _v,long long _c){
		v=_v;
		c=_c;
	}
	bool operator < (const data &other) const{
		return c>other.c;
	}
};
int n,dir,st,en;;
bool vis[N];
long long dis[N];
vector<data> _map[N];
void dij(int st){
	data u;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=2*(n+1);++i){
		dis[i]=INF;
	}
	dis[st]=0;
	priority_queue<data> q;;
	q.push(data(st,dis[st]));
	for(int i=0;i<2*(n+1);++i){
		u=q.top();
		q.pop();
		vis[u.v]=true;
		if(u.v==en) break;
		int sz=_map[u.v].size();
		for(int j=0;j<sz;++j){
			data ch=_map[u.v][j];
			if(!vis[ch.v] && dis[ch.v]>dis[u.v]+ch.c){
				dis[ch.v]=dis[u.v]+ch.c;
				q.push(data(ch.v,dis[ch.v]));
			}
		}
		while(!q.empty() && vis[q.top().v]){
			q.pop();
		}
		if(q.empty()){
			break;
		}
	}
}
int main(){
	long long d;
	while(scanf("%d",&n) && n){
	for(int i=0;i<2*(n+1);++i){
		_map[i].clear();
	}
	scanf("%d%d",&dir,&st);
	st+=dir*(n+1);
	scanf("%d%d",&dir,&en);
	en+=dir*(n+1);
	for(int i=0;i<n;++i){
		scanf("%I64d",&d);
		_map[i].push_back(data(i+1,d));
		_map[i+1].push_back(data(i,d));
	}
	for(int i=0;i<=n;++i){
		scanf("%I64d",&d);
		_map[i].push_back(data(i+n+1,d));
		_map[i+n+1].push_back(data(i,d));
	}
	for(int i=n+1;i<2*n+1;++i){
		scanf("%I64d",&d);
		_map[i].push_back(data(i+1,d));
		_map[i+1].push_back(data(i,d));
	}
	dij(st);
	cout<<dis[en]<<endl;
	}
	return 0;
}
