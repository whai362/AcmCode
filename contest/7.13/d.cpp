#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
char name1[205][105],name2[205][105];
int n,dp[205][2];
vector<int> _map[205];
int findName(char *str){
	for(int i=0;i<n;++i){
		if(strcmp(str,name1[i])==0){
			return i;
		}
	}
}
void Dp(int rt){
	int sz=_map[rt].size();
	int dp0=0,dp1=0;
	for(int i=0;i<sz;++i){
		int ch=_map[rt][i];
		Dp(ch);
		dp0+=max(dp[ch][0],dp[ch][1]);
		dp1+=dp[ch][0];
	}
	dp[rt][0]=dp0;
	dp[rt][1]=dp1+1;
}
bool unique(int rt,int flag){
	if(flag==0) return false;
	else if(flag==1){
		int sz=_map[rt].size();
		for(int i=0;i<sz;++i){
			int ch=_map[rt][i];
			if(!unique(ch,-1)) return false;
		}
		return true;
	}
	else{
		int sz=_map[rt].size();
		for(int i=0;i<sz;++i){
			int ch=_map[rt][i];
			int flag=0;
			if(dp[ch][0]>dp[ch][1]) flag=-1;
			else if(dp[ch][0]<dp[ch][1]) flag=1;
			if(!unique(ch,flag)) return false;
		}
		return true;
	}
}
int main(){
	while(scanf("%d",&n) && n){
		scanf("%s",name1[0]);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=n;++i){
			_map[i].clear();
		}
		for(int i=1;i<n;++i)
			scanf("%s%s",name1[i],name2[i]);
		for(int i=1;i<n;++i){
			int u=i,
				v=findName(name2[i]);
			_map[v].push_back(u);
		}
		Dp(0);
		int flag=0;
		if(dp[0][0]>dp[0][1]) flag=-1;
		else if(dp[0][0]<dp[0][1]) flag=1;
		//cout<<dp[0][0]<<' '<<dp[0][1]<<endl;
		printf("%d %s\n",max(dp[0][1],dp[0][0]),unique(0,flag)==true?"Yes":"No");
	}
	return 0;
}
