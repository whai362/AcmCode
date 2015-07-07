#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define PB push_back
#define MP make_pair
#define PII pair<int,int>
#define LL __int64
#define X first
#define Y second
const int MOD=998244353;
const int N=1005;
const int M=10;
int tran[N][M];

PII que[N*N];
int front,tail,used[N][N];
LL two[N];
vector<PII> e[N][N];

int fa[N];
int num[N];
int init_bcj(){
	for(int i=0;i<N;++i){
		fa[i]=i;
		num[i]=1;
	}
}
int getFa(int x){
	if(x!=fa[x]) return fa[x]=getFa(fa[x]);
	return x;
}
void bin(int x,int y){
	int fx=getFa(x);
	int fy=getFa(y);
	if(fx==fy) return ;
	fa[fy]=fx;
	num[fx]+=num[fy];
	num[fy]=0;
	//if(num[fx]<=num[fy]){
	//	num[fy]+=num[fx];
	//	fa[fx]=fy;
	//}
	//else{
	//	num[fx]+=num[fy];
	//	fa[fy]=fx;
	//}
}
int mark=0;
int main(){
	two[0]=1;
	for(int i=1;i<N;++i) two[i]=two[i-1]*2%MOD;
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		++mark;
		for(int i=1;i<=n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&tran[i][j]);
		init_bcj();
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				e[i][j].clear();
		for(int y1=0;y1<=n;++y1){
			for(int x1=0;x1<y1;++x1){
				for(int i=0;i<m;++i){
					int x2=tran[x1][i];
					int y2=tran[y1][i];
					if(x2>y2) swap(x2,y2);
					e[x2][y2].PB(MP(x1,y1));
				}
			}
		}

		front=tail=0;
		for(int i=1;i<=n;++i){
			++used[0][i];
			que[tail++]=MP(0,i);
		}
		while(front<tail){
			int x=que[front].X;
			int y=que[front].Y;
			++front;
			for(int i=0;i<e[x][y].size();++i){
				int x2=e[x][y][i].X;
				int y2=e[x][y][i].Y;
				if(used[x2][y2]!=mark){
					used[x2][y2]=mark;
					que[tail++]=MP(x2,y2);
				}
			}
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<i;++j)
				if(used[j][i]!=mark) bin(i,j);
		LL ans=two[n]-1;
		//cout<<ans<<endl;
		for(int i=1;i<=n;++i){
			if(num[i]){
				ans-=two[num[i]]-1;
			}
		}
		ans=(ans%MOD+MOD)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
