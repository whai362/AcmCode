#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
map<string,int> seq;
int goal[4][2];
int n,m;

int tab[][4]={
	1,2,4,8,
	3,4,8,0,
	5,2,8,0,
	9,2,4,0,
	6,1,8,0,
	10,1,4,0,
	12,1,2,0,
	7,8,0,0,
	11,4,0,0,
	13,2,0,0,
	14,1,0,0,
	15,0,0,0,
	3,12,0,0,
	5,10,0,0,
	9,6,0,0,
};

const int inf = 0x3f3f3f3f;
const int N = 205; //总顶点数
const int A = 10 ;  //要包含的顶点数
int id[A];         //包含顶点的序号
int d[N][N];       //距离矩阵
int dp[1<<A][N];  //dp[i][j]表示点j到联通的集合i的最短距离
void floyd(){
	for(int k=0;k<n;k++)      //vertex 0---n-1
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(d[i][j]>d[i][k]+d[k][j] && (d[i][k]!=inf && d[k][j]!=inf))
					d[i][j]=d[i][k]+d[k][j];
}

int stn(int a)
{
	int top = 1<<a;

	floyd();	

	for(int i=0;i<top;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=inf;

	for(int i=0;i<a;i++)
	{
		for(int j=0;j<n;j++)
			dp[1<<i][j]=d[id[i]][j];
	}
	for(int i=1;i<top;i++)
	{
		if(i&(i-1)==0)
			continue;
		for(int k=0;k<n;k++)   //init
		{
			for(int j=1;j<i;j++)
			{
				if((i|j)==i && dp[i][k]>dp[j][k]+dp[i-j][k])
					dp[i][k]=dp[j][k]+dp[i-j][k];
			}
		}

		for(int j=0;j<n;j++)  //update
		{
			for(int k=0;k<n;k++)
			{
				if(dp[i][j]>dp[i][k]+d[k][j])
					dp[i][j]=dp[i][k]+d[k][j];
			}
		}
	}

	int ans = inf;
	for(int i=0;i<n;i++)
	{
		if(ans > dp[top-1][i])
			ans=dp[top-1][i];
	}
	return ans;
}

int gao(int group){
	int cnt=0;
	int hash[N];
	memset(hash,0,sizeof(hash));
	//memset(dp,0,sizeof(dp));
	//memset(id,0,sizeof(id));
	for(int i=0;i<4;++i){
		if((1<<i) & group){
			if(hash[goal[i][0]]==0){
				id[cnt++]=goal[i][0];
				hash[goal[i][0]]=1;
			}
			if(hash[goal[i][1]]==0){
				id[cnt++]=goal[i][1];
				hash[goal[i][1]]=1;
			}
		}
	}
	if(cnt<=1) return 0;
	//cout<<cnt<<endl;
	return stn(cnt);
}

int main(){
	ios_base::sync_with_stdio(false);
	string name;
	while(cin>>n>>m && (n||m)){
		for(int i=0;i<n;++i){
			cin>>name;
			seq[name]=i;
		}
		string s,t;
		int c;
		memset(d,0x3f,sizeof(d));
		for(int i=0;i<n;++i)
			d[i][i]=0;
		for(int i=0;i<m;++i){
			cin>>s>>t>>c;
			int u,v;
			u=seq[s];
			v=seq[t];
			d[u][v]=d[v][u]=min(d[u][v],c);
			if(u==v) d[u][v]=0;
		}
		for(int i=0;i<4;++i){
			cin>>s>>t;
			goal[i][0]=seq[s];
			goal[i][1]=seq[t];
		}
		floyd();
		int ans=inf;
		//ans=gao(4);
		for(int i=0;i<15;++i){
			int tmp=0;
			for(int j=0;j<4;++j){
				tmp+=gao(tab[i][j]);
			}
			//cout<<tmp<<endl;
			ans=min(ans,tmp);
		}
		//ans=gao(tab[0][0]);
		cout<<ans<<endl;
	}
	return 0;
}
