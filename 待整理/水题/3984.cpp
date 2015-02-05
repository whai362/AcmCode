#include<cstdio>
#include<queue>
using namespace std;
int _x[4]={1,-1,0,0},_y[4]={0,0,1,-1},map[5][5],way[5][5];
struct point{
	int x,y;
};
bool in_map(int x,int y){
	if(x>4 || x<0 || y>4 || y<0) return 0;
	return 1;
}
void bfs(int x,int y){
	int i;
	point tmp_p;
	queue<point> q;
	tmp_p.x=x,tmp_p.y=y;
	q.push(tmp_p);
	way[x][y]=1;
	while(!q.empty()){
		x=q.front().x,y=q.front().y;
		q.pop();
		for(i=0;i<4;++i){
			if(in_map(x+_x[i],y+_y[i]) && map[x+_x[i]][y+_y[i]]==0 && !way[x+_x[i]][y+_y[i]]){
				tmp_p.x=x+_x[i],tmp_p.y=y+_y[i];
				q.push(tmp_p);
				way[x+_x[i]][y+_y[i]]=way[x][y]+1;
			}
		}
	}
	return ;
}
point find(int x,int y){
	int i,_min=10000;
	point tmp_p;	
	for(i=0;i<4;++i){
		if(in_map(x+_x[i],y+_y[i]) && way[x+_x[i]][y+_y[i]] && way[x+_x[i]][y+_y[i]]<_min){
			_min=way[x+_x[i]][y+_y[i]];
			tmp_p.x=x+_x[i],tmp_p.y=y+_y[i];
		}
	}
	return tmp_p;
}
int main(){
	int i,j;
	point p;
	for(i=0;i<5;++i)
	  for(j=0;j<5;++j)
		scanf("%d",&map[i][j]);
	bfs(4,4);
	printf("(%d, %d)\n",0,0);
	p=find(0,0);
	while(way[p.x][p.y]>1){
		printf("(%d, %d)\n",p.x,p.y);
		p=find(p.x,p.y);
	}
	printf("(%d, %d)\n",4,4);
	return 0;
}
