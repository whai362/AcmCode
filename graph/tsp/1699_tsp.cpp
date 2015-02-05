#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=15,
	  M=105;
char str[N][M];
int len[N],
	d[N][N];
int n,dp[1<<11][11];
const int inf=0x3f3f3f3f;

/*
   状态压缩求tsp问题。
   输入：点数n，距离矩阵d[][]，对角线为0。
   输出：最短距离。
   已经处理0的情况
 */
int DP(){
	if(n==0) return 0;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<(1<<n);++i)
		for(int j=0;j<n;j++){
			dp[i][j]=inf;
			if(i&(1<<j)){
				if((i^(1<<j))==0) dp[i][j]=len[j]; 
				else{
					for(int k=0;k<n;k++){
						if((i&(1<<k)) && j!=k){
							dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+d[k][j]); 
						}
					}
				}
			}
		}
	int ans=inf; 
	for(int i=0;i<n;i++) 
		ans=min(ans,dp[(1<<n)-1][i]); 
	printf("%d\n",ans); 
}

void init(){
	memset(d,0,sizeof(d));
}
void deal(int u,int v){
	int i,
		l1=len[u],
		l2=len[v];
	for(i=0;i<l1;++i){
		if(i+l2<l1) continue;
		int flag=1;
		for(int j=0;i+j<l1;++j){
			if(str[v][j]!=str[u][i+j]){
				flag=0;
				break;
			}
		}
		if(flag){
			d[u][v]=l2-(l1-i);
			break;
		}
	}
	if(i==l1) d[u][v]=l2;
	for(i=0;i<l2;++i){
		if(i+l1<l2) continue;
		int flag=1;
		for(int j=0;i+j<l2;++j){
			if(str[u][j]!=str[v][i+j]){
				flag=0;
				break;
			}
		}
		if(flag){
			d[v][u]=l1-(l2-i);
			break;
		}
	}
	if(i==l2) d[v][u]=l1;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=0;i<n;++i){
			scanf("%s",str[i]);
			len[i]=strlen(str[i]);
		}
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				deal(i,j);
			}
		}
		DP();
	}
	return 0;
}
