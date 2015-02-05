#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define N 1005
#define M 1005
struct Node{
	int v,c;
	Node *next;
}p[M];
struct Head{
	Node *fir;
}h[N];
struct Data{
	int v,c;
	Data(){}
	Data(int v,int c){
		this->v=v;
		this->c=c;
	}
	bool operator < (const Data &other) const{
		return c>other.c;
	}
};
int n,m;
int dis[N];
bool vis[N];
void addnode(int u,int v,int c){
	Node *p=new Node();
	p->v=v;
	p->c=c;
	p->next=h[u-1].fir;
	h[u-1].fir=p;
}
void init(){
	int u,v,c;
	int i;
	for(i=0;i<n;++i){
		h[i].fir=NULL;
	}
	for(i=0;i<m;++i){
		cin>>u>>v>>c;
		addnode(u,v,c);
	}
}
void dij(int src){
	int i;
	Node *j;
	Data u;
	memset(vis,0,sizeof(vis));
	for(i=0;i<=n;++i) dis[i]=INF;
	dis[src]=0;
	priority_queue<Data> q;
	q.push(Data(src,dis[src]));
	for(i=0;i<n;++i){
		u=q.top();
		q.pop();
		vis[u.v]=1;
		for(j=h[u.v-1].fir;j;j=j->next){
			if(!vis[j->v] && dis[j->v]>dis[u.v]+j->c){
				dis[j->v]=dis[u.v]+j->c;
				q.push(Data(j->v,dis[j->v]));
			}
		}
		while(!q.empty() && vis[q.top().v]) q.pop();
		if(q.empty()) break;
	}
}
int main(){
	int src=1;
	cin>>n>>m;
	init();
	dij(src);
	cout<<"Êä³ö1->5×î¶ÌÂ·£º"<<endl<<dis[5]<<endl;
	return 0;
}
