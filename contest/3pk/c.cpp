#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct point{
	int x,y;
	point(){}
	point(int x,int y){
		this->x=x;
		this->y=y;
	}
};
bool vis[25][25];
char s[25][25];
int w,h,ans;
bool ok(int x,int y){
	if(x>=0 && x<h && y>=0 && y<w){
		if(s[x][y]=='.' && !vis[x][y]){
			vis[x][y]=1;
			++ans;
			return true;
		}
		else return false;
	}
	return false;
}
int main(){
	int i,j,x,y,x0,y0;
	point tmp;
	while(scanf("%d%d",&w,&h) && (w||h)){
		ans=0;
		memset(vis,0,sizeof(vis));
		queue<point> q;
		for(i=0;i<h;++i){
			scanf("%s",s[i]);
			for(j=0;j<w;++j){
				if(s[i][j]=='@'){
					x0=i;
					y0=j;
				}
			}
		}
		q.push(point(x0,y0));
		while(!q.empty()){
			tmp=q.front();
			q.pop();
			if(ok(tmp.x-1,tmp.y)) q.push(point(tmp.x-1,tmp.y));
			if(ok(tmp.x+1,tmp.y)) q.push(point(tmp.x+1,tmp.y));
			if(ok(tmp.x,tmp.y-1)) q.push(point(tmp.x,tmp.y-1));
			if(ok(tmp.x,tmp.y+1)) q.push(point(tmp.x,tmp.y+1));
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
