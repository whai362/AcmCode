#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
#define Min(x,y) ((x)<(y)?(x):(y))
#define inf 1000000000
#define N 205
struct point{
	int x,y;
}p[N*N];
double map[N][N],t[N];
bool vis[N];
int n;
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dij(int S,int T){
	int i,j,k;
	double tmp;
	memset(vis,0,sizeof(vis));
	for(i=0;i<n;++i) t[i]=map[S][i];
	vis[S]=1;
	for(i=1;i<n;++i){
		tmp=inf,k=S;
		for(j=1;j<n;++j){
			if(!map[j][i]||vis[j]) continue;
			if(tmp>t[j]){
				tmp=t[j];
				k=j;
			}
		}
		vis[k]=1;
		if(k==T) return tmp;
		for(j=1;j<=n;++j){
			if(vis[j]) continue;
			t[j]=Min(t[j],t[k]+map[k][j]);
		}
	}
}
int main(){
	int i,j,flag=0;
	double ans;
	n=2;
	memset(map,9999999,sizeof(map));
	scanf("%d%d%d%d",&p[0].x,&p[0].y,&p[1].x,&p[1].y);
	while(scanf("%d%d",&p[n].x,&p[n].y)!=EOF){
		if(p[n].x==-1&&p[n].y==-1){ flag=0; continue; }
		if(flag) map[n-1][n]=map[n][n-1]=dis(p[n],p[n-1])/1000/40*60;
		flag=1,++n;
	}
	for(i=0;i<n-1;++i)
	  for(j=i+1;j<n;++j){
		  if(p[i].x!=-1&&p[j].x!=-1&&map[i][j]>inf){
			  map[i][j]=map[j][i]=dis(p[i],p[j])/1000/10*60;
		  }
	  }
	ans=dij(0,1);
	printf("%.0f\n",ans);
	return 0;
}
