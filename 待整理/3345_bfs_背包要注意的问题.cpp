#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f;
struct Data{
	int cnt;
	char name[105],sub[205][105];
}d[205];
int n,m,cnt;
int count[205],cost[205];
int dp[205][205];
bool vis[205];
char name[205][105];
vector<int> _map[205];
int getId(char *str){
	for(int i=1;i<=n;++i){
		if(strcmp(str,name[i])==0)
			return i;
	}
}
int getCount(int rt){
	int sz=_map[rt].size();
	for(int i=0;i<sz;++i){
		count[rt]+=getCount(_map[rt][i]);
	}
	return count[rt];
}
void Dp(int rt){
	int sz=_map[rt].size();
	for(int i=0;i<sz;++i){
		int ch=_map[rt][i];
		Dp(ch);
	}
	dp[rt][0]=0;
	for(int i=1;i<=count[rt];++i)
		dp[rt][i]=cost[rt];
	for(int i=0;i<sz;++i){
		int ch=_map[rt][i];
		/*int tmp[205];			
		for(int j=0;j<=count[rt];++j){
			tmp[j]=dp[rt][j];
		}
		for(int j=0;j<=count[ch];++j){
			for(int k=j;k<=count[rt];++k){
				if(tmp[k]>dp[rt][k-j]+dp[ch][j]){	//tmp[k]不能改成dp[rt][k]因为dp[rt][k]不是更新的目标
					tmp[k]=dp[rt][k-j]+dp[ch][j];
				}
			}
		}
		for(int j=0;j<=count[rt];++j){
			dp[rt][j]=tmp[j];
		}*/
		for(int k = count[rt]; k >= 0; k--){	//翔哥的写法，比较好
			for(int j = 0; j <= min(k, count[ch]); j++){
				if(dp[rt][k] > dp[rt][k - j] + dp[ch][j]){
					dp[rt][k] = dp[rt][k - j] + dp[ch][j];
				}
			}
		}
	}
}
int main(){
	char op[15];
	while(scanf("%s",op) && op[0]!='#'){
		sscanf(op,"%d",&n);
		scanf("%d",&m);
		cnt=1;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<=n;++i)
			count[i]=1;
		for(int i=1;i<=n;++i){
			scanf("%s%d",d[i].name,&cost[i]);
			strcpy(name[cnt++],d[i].name);
			d[i].cnt=0;
			char ch;
			ch=getchar();
			while(ch!='\n'){
				scanf("%s",d[i].sub[d[i].cnt++]);
				ch=getchar();
			}
		}
		for(int i=0;i<=n;++i){
			_map[i].clear();
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<d[i].cnt;++j){
				int v=getId(d[i].sub[j]);
				_map[i].push_back(v);
				vis[v]=true;
			}
		}
		cost[0]=0;
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				cost[0]+=cost[i];
				_map[0].push_back(i);
			}
		}
		getCount(0);
		--count[0];
		Dp(0);
		int ans=INF;
		for(int i=m;i<=n;++i){
			ans=min(ans,dp[0][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
