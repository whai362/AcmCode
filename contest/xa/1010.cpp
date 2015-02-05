#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;
const int Maxn=20;
char st[Maxn][Maxn];
int n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int vis[Maxn][Maxn],dis[Maxn][Maxn];
int src,des;

struct Node{
	int x,y;
	Node(){}
	Node(int _x,int _y){
		x=_x;y=_y;
	}
}s[Maxn],e[Maxn];
bool ok(int x,int y){
	if(x>=0&&x<n&&y>=0&&y<n&&st[x][y]=='.'&&vis[x][y]==-1) return true;
	return false;
}
void bfs(int i){
	queue<Node> q;
	memset(vis,-1,sizeof(vis));
	int h=1,t=1;q.push(e[i]);vis[e[i].x][e[i].y]=0;
	while (!q.empty()){
		Node now=q.front();
		q.pop();
		for (int k=0;k<4;k++){
			int tx=now.x+dx[k],ty=now.y+dy[k];
			if (ok(tx,ty)){
				q.push(Node(tx,ty));
				vis[tx][ty]=vis[now.x][now.y]+1;
			}
		}
	}
	return ;
}

int main(){
	while (~scanf("%d%d",&n,&m)){
		for (int i=0;i<n;i++){
			scanf("%s",st[i]);
		}
		for (int i=1;i<=m;i++){
			scanf("%d%d%d%d",&s[i].x,&s[i].y,&e[i].x,&e[i].y);
			s[i].x--;s[i].y--;e[i].x--;e[i].y--;
		}
		for (int i=1;i<=m;i++){
			bfs(i);
			for (int j=1;j<=m;j++){
				if(i!=j){
					dis[i][j]=vis[s[j].x][s[j].y];
				}
			}
		}
	}
	return 0;
}

