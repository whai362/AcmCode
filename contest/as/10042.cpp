#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int D=10005,N=55;
double dp[D][N];
int n,m,d;
vector<int> _map[N];
void init(){
	for(int i=0;i<=n;++i){
		_map[i].clear();
	}
}
double gao(int pos){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;++i){
		dp[0][i]=1.0/n;
	}
	double ret=1.0;
	for(int i=0;i<=d;++i){
		ret-=dp[i][pos];
		//cout<<dp[i][pos]<<endl;
		dp[i][pos]=0;
		for(int j=1;j<=n;++j){
			int sz=_map[j].size();
			for(int k=0;k<sz;++k){
				int ch=_map[j][k];
				dp[i+1][ch]+=dp[i][j]*1.0/sz;
			}
		}
	}
	return ret;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	scanf("%d%d%d",&n,&m,&d);
	init();
	int u,v;
	for(int i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		_map[u].push_back(v);
		_map[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		printf("%.10lf\n",gao(i));
	}
	}
	return 0;
}
