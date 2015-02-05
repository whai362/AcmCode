#include<iostream>
#include<queue>
#define Max 201
using namespace std;
int _map[Max][Max];//记录原图边i到j的最大流量
int min(int a,int b){
	return a<b? a:b;
}
int maxflow(int s,int t){//s是源点t是汇点也是节点的最大值，计算从s到t的最大流
	int f=0;//最大流
	int a[Max];//记录当前路径的容许的最大流
	bool visit[Max];
	int flow[Max][Max];//记录边i到j已占用了的流量
	int p[Max];//记录流的上一个结点，即从p[i]流向i
	int u,i;
	queue<int> q;
	memset(flow,0,sizeof(flow));
	while(1){
		memset(visit,0,sizeof(visit));
		memset(a,0,sizeof(a));
		a[s]=INT_MAX;
		visit[s]=1;
		q.push(s);
		while(!q.empty()){
			u=q.front();
			q.pop();
			for(i=1;i<=t;i++){
				if(!visit[i]&&_map[u][i]-flow[u][i]>0){
					visit[i]=1;
					a[i]=min(a[u],_map[u][i]-flow[u][i]);
					p[i]=u;
					q.push(i);
				}
			}
		}
		if(a[t]==0)break;
		for(i=t;i!=s;i=p[i]){
			flow[i][p[i]]-=a[t];
			flow[p[i]][i]+=a[t];
		}
		f+=a[t];
	}
	return f;
}
int main(){
	int n,m,i,u,v,w;
	while(cin>>n>>m){
		memset(_map,0,sizeof(_map));  
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&u,&v,&w);
			_map[u][v]+=w;
		}
		cout<<maxflow(1,m)<<endl; 
	}
	return 0;
}
