#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define LL __int64
#define PB push_back
const int N=10005;
const int INF=1000000;
vector<int> G[N];
//queue<int> q;
int q[N];
int front,tail;
int col[N];
int vis[N];
void In(int &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

void In(LL &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

void Out(int x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

void Out(LL x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

void gao(int n,int m){
	front=tail=0;
	//q.push(1);
	q[tail++]=1;
	vis[1]=1;
	while(front!=tail){
		int now=q[front++];
		//int now=q.front();
		//q.pop();
		int _max=0,_min=INF;
		for(int i=0;i<G[now].size();++i){
			int ch=G[now][i];
			_max=max(col[ch],_max);
			if(col[ch]) _min=min(col[ch],_min);
			if(vis[ch]==0){
				//q.push(ch);
				q[tail++]=ch;
				vis[ch]=1;
			}
		}
		if(_min!=1) col[now]=1;
		else col[now]=_max+1;
	}
	for(int i=1;i<=n;++i){
		//printf("%d\n",col[i]);
		Out(col[i]);
		puts("");
	}
}
void init(int n,int m){
	memset(col,0,sizeof(col));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;++i)
		G[i].clear();
}
int main(){
	int T;
	int n,m;
	//scanf("%d",&T);
	In(T);
	while(T--){
		//scanf("%d%d",&n,&m);
		In(n);
		In(m);
		init(n,m);
		int u,v;
		for(int i=0;i<m;++i){
			//scanf("%d%d",&u,&v);
			In(u);
			In(v);
			G[u].PB(v);
			G[v].PB(n);
		}
		gao(n,m);
	}
	return 0;
}
