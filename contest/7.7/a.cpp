#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=205,
		  INF=0x3f3f3f3f;
struct Data{
	int x,y;
	Data(){}
	Data(int _x,int _y){
		x=_x;
		y=_y;
	}
}d[20];
int ans,cnt,n,m,goal;
char _map[N][N];
int dx1[]={-1,0,1,0},
	dy1[]={0,1,0,-1},
	dx2[]={0,1,0,-1},
	dy2[]={1,0,-1,0};
bool getPos(int n,int pos){
	int tmp=1<<pos;
	if(n&tmp) return true;
	return false;
}
int setPos(int n,int pos){
	int tmp=1<<pos;
	n|=tmp;
	return n;
}
bool in(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m)
		return true;
	return false;
}
bool ok(int i,int j,int n){
	int x1=d[i].x+dx1[j],
		y1=d[i].y+dy1[j],
		x2=d[i].x+dx2[j],
		y2=d[i].y+dy2[j];
	//cout<<i<<' '<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
	n=setPos(n,_map[d[i].x][d[i].y]);
	if(in(x1,y1)){
		if(_map[x1][y1]=='#')
			return false;
		else{
			n=setPos(n,_map[x1][y1]);
			//if(n==goal)
			//	return true;
		}
	}
	if(in(x2,y2)){
		if(_map[x2][y2]=='#')
			return false;
		else{
			n=setPos(n,_map[x2][y2]);
			//if(n==goal)
			//	return true;
		}
	}
	if(n==goal) return true;
	return false;
}
bool legal(int i){
	int x1=d[i].x+dx1[0],
		y1=d[i].y+dy1[0],
		x2=d[i].x+dx2[0],
		y2=d[i].y+dy2[0];
	if((in(x1,y1) && _map[x1][y1]=='#') || (in(x2,y2) && _map[x2][y2]=='#')){
		return false;
	}
	return true;

}
int extend(int i,int n){
	int x1=d[i].x+dx1[0],
		y1=d[i].y+dy1[0],
		x2=d[i].x+dx2[0],
		y2=d[i].y+dy2[0];
	if(in(x1,y1)){
		n=setPos(n,_map[x1][y1]);
	}
	if(in(x2,y2)){
		n=setPos(n,_map[x2][y2]);
	}
	return n;
}
void gao(int n){
	int tmp=0,copy=n;
	//cout<<'!'<<n<<endl;
	for(int i=0;i<cnt;++i){
		if(copy&1){
			if(legal(i))
				++tmp;
			else
				return ;
		}
		copy>>=1;
	}
	copy=n;
	int t[cnt];
	memset(t,0,sizeof(t));
	for(int i=0;i<cnt;++i){
		if(copy&1){
			t[i]=extend(i,n);
		}
		copy>>=1;
	}
	for(int i=0;i<cnt;++i){
		n|=t[i];
	}
	//cout<<n<<endl;
	for(int i=0;i<cnt;++i){
		for(int j=0;j<4;++j){
			if(ok(i,j,n)){
				ans=min(ans,tmp+1);
			}
		}
	}
}
int main(){
	while(scanf("%d%d",&n,&m) && (n||m)){
	for(int i=0;i<n;++i){
		scanf("%s",_map[i]);
	}
	cnt=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(_map[i][j]=='.'){
				d[cnt]=Data(i,j);
				_map[i][j]=cnt++;
			}
		}
	}
	ans=INF;
	goal=(1<<cnt)-1;
	int all=1<<cnt;
	for(int i=0;i<all;++i){
		gao(i);
	}
	if(cnt && ans==INF) cout<<-1<<endl;
	else if(cnt==0) cout<<0<<endl;
	else cout<<ans<<endl;
	}
	return 0;
}
