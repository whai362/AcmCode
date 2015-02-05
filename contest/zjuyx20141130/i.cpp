#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int hash[500];
bool vis[105][105];
char _map[105][105];
struct Point{
	int x,y;
}o;
int ans,_max,cnt;
int _abs(int x){
	if(x<0) return -x;
	return x;
}
int dx[]={-1,-1,1,1},
	dy[]={-1,1,1,-1};
void gao(int x,int y){
	if(vis[x][y]) return ;
	//cout<<x<<' '<<y<<endl;
	char ch=_map[x][y];
	vis[x][y]=true;
	++cnt;
	++hash[ch];
	_max=max(_max,hash[ch]);
	int ax,ay;
	ax=_abs(o.x-x);
	ay=_abs(o.y-y);
	for(int i=0;i<4;++i){
		int tmpx=o.x+dx[i]*ax;
		int tmpy=o.y+dy[i]*ay;
		gao(tmpx,tmpy);
	}
	int tmpx,tmpy;
	tmpx=x-o.x;
	tmpy=y-o.y;
	swap(tmpx,tmpy);
	int x1=tmpx+o.x;
	int y1=tmpy+o.y;
	gao(x1,y1);
	int x2=-tmpx+o.x;
	int y2=-tmpy+o.y;
	gao(x2,y2);
}
int main(){
	int n;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%s",_map[i]);
		}
		o.x=o.y=(n-1)/2;
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(vis[i][j]) continue;
				memset(hash,0,sizeof(hash));
				_max=cnt=0;
				gao(i,j);
				//cout<<"-----"<<endl;
				//cout<<"!"<<cnt<<' '<<_max<<endl;
				ans+=cnt-_max;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
