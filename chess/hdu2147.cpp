#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2005;
int dp[N][N];
int dx[]={1,1,0};
int dy[]={0,1,1};
int n,m;
bool in(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m) return true;
	return false;
}
bool win(int x,int y){
	for(int i=0;i<3;++i){
		int tmpx=x+dx[i];
		int tmpy=y+dy[i];
		if(in(tmpx,tmpy) && dp[tmpx][tmpy]==1) return true;
	}
	return false;
}
bool fail(int x,int y){
	for(int i=0;i<3;++i){
		int tmpx=x+dx[i];
		int tmpy=y+dy[i];
		if(!in(tmpx,tmpy)) continue;
		//if(x==2 && y==0) cout<<tmpx<<' '<<tmpy<<endl;
		if(dp[tmpx][tmpy]!=0) return false;
	}
	return true;
}
void gao(int n,int m){
	memset(dp,-1,sizeof(dp));
	//0代表赢，1代表输
	for(int i=n-1;i>=0;--i){
		for(int j=m-1;j>=0;--j){
			if(i==n-1 && j==m-1){
				dp[i][j]=1;
				continue;
			}
			if(win(i,j)) dp[i][j]=0;
			else if(fail(i,j)) dp[i][j]=1;
		}
	}
	//for(int i=0;i<n;++i){
	//	for(int j=0;j<m;++j){
	//		cout<<dp[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
	if(dp[0][0]==1) puts("What a pity!");
	else puts("Wonderful!");
}
int main(){
	while(scanf("%d%d",&n,&m) && (n || m)){
		gao(n,m);
	}
	return 0;
}
