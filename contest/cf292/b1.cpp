#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define PB push_back
char mp[2005][2005];
int seq[2005][2005];
int vis[2005*2005];
int du[2005*2005];
queue<int> q;
vector<int> _map[2005*2005];
int kong=0;
int dx[]={0,1};
int dy[]={1,0};
int n,m;
bool ok(int x,int y){
	if(x<n && y<m && mp[x][y]=='.') return true;
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%s",mp[i]);
	int cnt=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(mp[i][j]=='.') ++kong;
			seq[i][j]=cnt++;
		}
	}
	if(kong==0){
		for(int i=0;i<n;++i)
				puts(mp[i]);

	  return 0; }
	int _min=100;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(mp[i][j]=='.'){
			for(int k=0;k<2;++k){
				int x=i+dx[k];
				int y=j+dy[k];
				if(ok(x,y)){
					_map[seq[i][j]].PB(seq[x][y]);
					_map[seq[x][y]].PB(seq[i][j]);
					++du[seq[i][j]];
					++du[seq[x][y]];
					_min=min(_min,min(du[seq[i][j]],du[seq[x][y]]));
				}
			}
			}
		}
	}
	if(_min>1) puts("Not unique");
	else{
		int fd=0;
		for(int i=0;i<cnt;++i){
			if(du[i]==1){
				q.push(i);
				vis[i]=1;
				//cout<<i/m<<' '<<i%m<<endl;
			}
		}
		//cout<<q.size()<<endl;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			int x0=now/m,y0=now%m;
			//cout<<x0<<' '<<y0<<endl;
			for(int i=0;i<_map[now].size();++i){
				int ch=_map[now][i];
				int x1=ch/m,y1=ch%m;
				if(mp[x1][y1]=='.'){
					//cout<<'|'<<x1<<' '<<y1<<endl;
					fd+=2;
					vis[ch]=1;
					if(x0==x1){
						mp[x0][y0]='<';
						mp[x1][y1]='>';
						if(y0>y1) swap(mp[x0][y0],mp[x1][y1]);
					}
					else{
						mp[x0][y0]='^';
						mp[x1][y1]='v';
						if(x0>x1) swap(mp[x0][y0],mp[x1][y1]);
					}
					for(int j=0;j<_map[ch].size();++j){
						int su=_map[ch][j];
						--du[su];
						if(du[su]==1){
							vis[su]=1;
							q.push(su);
						}
					}
					break;
				}
			}
		}
		if(fd==kong){
			for(int i=0;i<n;++i)
				puts(mp[i]);
		}
		else puts("Not unique");
	}
	return 0;
}
