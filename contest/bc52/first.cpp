#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int d[17][17],n,m,dp[1<<17][17];
const int INF=0x3f3f3f3f;
void floyd(){
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++) {
			if(d[i][k] == INF) continue;
			for(int j=0;j<n;j++){
				if(d[k][j] == INF) continue;
				if(d[i][k]+d[k][j]<d[i][j])
					d[i][j]=d[i][k]+d[k][j];
			}
		}
}
int DP(){
	if(n==0) return 0;
	memset(dp,0,sizeof(dp));
	int ans=INF;
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<n+1;j++)
			if(i==(1<<(j-1)))
				dp[i][j]=d[0][j];
			else if(i&(1<<(j-1))){		
				dp[i][j]=INF;
				for(int k=1;k<n+1;k++)
					if(k!=j&&(i&(1<<(k-1))))
						dp[i][j]=min(dp[i^(1<<(j-1))][k]+d[k][j],dp[i][j]);
			}
	for(int i=1;i<n+1;i++){
		ans=min(ans,dp[(1<<n)-1][i]+d[i][0]);
	}
	return ans;
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		memset(d, 0x3f, sizeof(d));
		for(int i = 0; i < n; ++i) {
			d[i][i] = 0;
		}
		for(int i = 0; i < m; ++i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u, --v;
			d[u][v] = d[v][u] = min(d[u][v], c);
		}
		//for(int i = 0; i < n; ++i) {
		//	for(int j = 0; j < n; ++j) {
		//		cout<<d[i][j]<<' ';
		//	}
		//	cout<<endl;
		//}
		floyd();
		//for(int i = 0; i < n; ++i) {
		//	for(int j = 0; j < n; ++j) {
		//		cout<<d[i][j]<<' ';
		//	}
		//	cout<<endl;
		//}
		--n;
		printf("%d\n",DP());
	}
	return 0;
}

