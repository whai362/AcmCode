#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=105,
		  Z=27,
	      INF=0x3f3f3f3f;
struct Data{
	int x,y;
	Data(){}
	Data(int _x,int _y){
		x=_x;
		y=_y;
	}
};
int n,m;
char _map[N][N];
int dp[N][N][Z],
	dx[]={1,-1,0,0},
	dy[]={0,0,1,-1};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m &&
	  _map[x][y]!='*' && _map[x][y]!='#'){
		bool flag=true;
		for(char i='A';i<='Z';++i){
			if(_map[x][y]==i){
				flag=false;
			}
		}
		return flag;
	}
	return false;
}
void gao(){
	queue<Data> q;
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<m;++i){
		if(_map[0][i]=='#'){
			q.push(Data(0,i));
			dp[0][i][0]=0;
		}
		else if(_map[0][i]!='*'){
			q.push(Data(0,i));
			dp[0][i][_map[0][i]-'A']=0;
		}
		if(_map[n-1][i]=='#'){
			q.push(Data(n-1,i));
			dp[n-1][i][0]=0;
		}
		else if(_map[n-1][i]!='*'){
			q.push(Data(n-1,i));
			dp[n-1][i][_map[n-1][i]-'A']=0;
		}
	}
	for(int i=0;i<n;++i){
		if(_map[i][0]=='#'){
			q.push(Data(i,0));
			dp[i][0][0]=0;
		}
		else if(_map[i][0]!='*'){
			q.push(Data(i,0));
			dp[i][0][_map[i][0]-'A']=0;
		}
		if(_map[i][m-1]=='#'){
			q.push(Data(i,m-1));
			dp[i][m-1][0]=0;
		}
		else if(_map[i][m-1]!='*'){
			q.push(Data(i,m-1));
			dp[i][m-1][_map[i][m-1]-'A']=0;
		}
	}
	while(!q.empty()){
		Data now=q.front();
		for(int i=0;i<
	}
}
int main(){
	int cnt=0;
	scanf("%s",_map[cnt++]);
	getchar();
	while(cin.getline(_map[cnt],sizeof(_map[cnt])) &&
		  _map[cnt++][0]!=0);
	n=cnt-1;
	m=strlen(_map[0]);
	return 0;
}

