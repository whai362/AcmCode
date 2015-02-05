#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Data{
	int x,y;
	Data(){};
	Data(int _x,int _y){
		x=_x;
		y=_y;
	}
}da[205];
int n,m,k;
int _map[105][105];
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};

char ans[105][105];
bool in(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m)
		return true;
	return false;
}
const int inf = 0x3f3f3f3f;
const int N = 205; //总顶点数
const int A = 7 ;  //要包含的顶点数
int id[A];         //包含顶点的序号
int d[N][N];       //距离矩阵
int dst[N][N][7];
int dp[1<<A][N];  //dp[i][j]表示点j到联通的集合i的最短距离
int dpst[1<<A][N][7];
//返回最小值
void floyd(int n){
	for(int k=0;k<n;k++)      //vertex 0---n-1
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(d[i][j]>d[i][k]+d[k][j]-_map[da[k].x][da[k].y] && (d[i][k]!=inf && d[k][j]!=inf)){
					d[i][j]=d[i][k]+d[k][j]-_map[da[k].x][da[k].y];
					for(int l=0;l<7;++l)
						dst[i][j][l]=dst[i][k][l] | dst[k][j][l];	
				}
			}
}
int stn(int n,int a){
	int top = 1<<a;
	
	for(int i=0;i<top;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=inf;

	for(int i=0;i<a;i++){
		for(int j=0;j<n;j++){
			dp[1<<i][j]=d[id[i]][j];
			for(int l=0;l<7;++l)
				dpst[1<<i][j][l]=dst[id[i]][j][l];
		}
	}
	for(int i=1;i<top;i++){
		if(i&(i-1)==0)
			continue;
		for(int k=0;k<n;k++){   //init
			for(int j=1;j<i;j++){
				if((i|j)==i && dp[i][k]>dp[j][k]+dp[i-j][k]-_map[da[k].x][da[k].y]){
					dp[i][k]=dp[j][k]+dp[i-j][k]-_map[da[k].x][da[k].y];
					for(int l=0;l<7;++l)
						dpst[i][k][l]=dpst[j][k][l] | dpst[i-j][k][l];
					int t1=k/30;
					int t2=k%30;
					dpst[i][k][t1] |= (1<<t2);
				}
			}
		}

		for(int j=0;j<n;j++){  //update
			for(int k=0;k<n;k++){
				if(dp[i][j]>dp[i][k]+d[k][j]-_map[da[k].x][da[k].y]){
					dp[i][j]=dp[i][k]+d[k][j]-_map[da[k].x][da[k].y];
					for(int l=0;l<7;++l)
						dpst[i][j][l]=dpst[i][k][l] | dst[k][j][l];
				}
			}
		}
	}

	int ans = inf;
	int tmp = inf;
	for(int i=0;i<n;i++){
		if(tmp > dp[top-1][i]){
			tmp=dp[top-1][i];
			ans=i;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&_map[i][j]);
	int cnt=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			da[cnt++]=Data(i,j);
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<cnt;++i){
		d[i][i]=_map[da[i].x][da[i].y];
		int t1=i/30;
		int t2=i%30;
		dst[i][i][t1]=(1<<t2);
		for(int j=0;j<4;++j){
			int tmpx=da[i].x+dx[j];
			int tmpy=da[i].y+dy[j];
			if(in(tmpx,tmpy)){
				int to=tmpx*m+tmpy;
				d[i][to]=_map[da[i].x][da[i].y]+_map[tmpx][tmpy];
				t1=i/30;
				t2=i%30;
				dst[i][to][t1] |= (1<<t2);
				t1=to/30;
				t2=to%30;
				dst[i][to][t1] |= (1<<t2);
			}
		}
	}
	floyd(cnt);
	int u,v;
	memset(ans,'.',sizeof(ans));
	for(int i=0;i<k;++i){
		scanf("%d%d",&u,&v);
		--u;
		--v;
		ans[u][v]='X';
		id[i]=u*m+v;
	}
	int top=(1<<k);
	int ans_id=stn(cnt,k);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			int seq=i*m+j;
			int t1=seq/30;
			int t2=seq%30;
			if(dpst[top-1][ans_id][t1] & (1<<t2)) ans[i][j]='X';
		}
	}
	printf("%d\n",dp[top-1][ans_id]);
	for(int i=0;i<n;++i){
		ans[i][m]=0;
		puts(ans[i]);
	}
	return 0;
}
