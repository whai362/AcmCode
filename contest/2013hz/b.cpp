#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=105,
	  inf=0x3f3f3f3f;
int n,m,bao_cnt;
char _map[N][N];
bool vis[N][N];
int d[10][10];
struct Node{
	int x,y,s;
	Node(){}
	Node(int xx,int yy,int ss){
		x=xx;y=yy;s=ss;
	}
};

int dp[1<<11][11];
int DP(){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(d[i][j]==inf) return inf;
		}
	}
	//cout<<"?"<<endl;
	if(n==0) return 0;
	memset(dp,0,sizeof(dp));
	int ans=inf;
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<n+1;j++)
			if(i==(1<<(j-1)))
				dp[i][j]=d[0][j];
			else if(i&(1<<(j-1))){		
				dp[i][j]=inf;
				for(int k=1;k<n+1;k++)
					if(k!=j&&(i&(1<<(k-1))))
						dp[i][j]=min(dp[i^(1<<(j-1))][k]+d[k][j],dp[i][j]);
			}
	for(int i=1;i<n+1;i++){
		ans=min(ans,dp[(1<<n)-1][i]);
	}
	return ans;
}

bool reach(int x,int y){
	if (x>=0&&x<n&&y>=0&&y<m&&_map[x][y]!='#'&&!vis[x][y])
		return true;
	return false;
}
int dx[]={1,-1,0,0},
	dy[]={0,0,1,-1};
void bfs(int x,int y){
	memset(vis,false,sizeof(vis));
	queue<Node> que;
	que.push(Node(x,y,0));vis[x][y]=true;
	d[_map[x][y]-'0'][_map[x][y]-'0']=0;
	while (!que.empty()){
		Node u=que.front();que.pop();
		Node v;
		for (int k=0;k<4;k++){
			v.x=u.x+dx[k];v.y=u.y+dy[k];v.s=u.s+1;
			if (reach(v.x,v.y)){
				que.push(v);
				vis[v.x][v.y]=true;
				if (_map[v.x][v.y]>='0'&&_map[v.x][v.y]<='9'){
					d[_map[x][y]-'0'][_map[v.x][v.y]-'0']=v.s;
				}
			}
		}
	}
}
void predo(){
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if (_map[i][j]>='0'&&_map[i][j]<='9')
				bfs(i,j);
		}
	}
}
int main(){
	int T;
	while(scanf("%d%d",&n,&m) && (n||m)){
		for(int i=0;i<n;++i){
			scanf("%s",_map[i]);
			for(int j=0;j<m;j++)
				if (_map[i][j]=='@') _map[i][j]='0';
		}
		scanf("%d",&bao_cnt);
		int x,y;
		for(int i=0;i<bao_cnt;++i){
			scanf("%d%d",&x,&y);
			_map[x-1][y-1]=i+1+'0';
		}
		//cout<<'!'<<endl;
		predo();
		n=bao_cnt;
		//for(int i=0;i<n;++i){
		//	for(int j=0;j<n;++j){
		//		cout<<d[i][j]<<' ';	
		//	}
		//	cout<<endl;
		//}
		int ans=DP();
		if(ans==inf) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}
