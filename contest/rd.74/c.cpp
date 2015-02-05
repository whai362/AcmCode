#include<cstdio>
#include<queue>
using namespace std;
struct point{
	int x,y;
	point(int x,int y){
		this->x=x;
		this->y=y;
	}
};
int m[150][150];
int tox(int x){ return x+75; }
int toy(int y){ return y+75; }
bool inmap(int x,int y){
	if(x+75>=0 && x+75<150 && y+75>=0 && y+75<150) return 1;
	return 0;
}
int main(){
	int i,n,t;
	queue<point> q;
	scanf("%d%d",&n,&t);
	m[tox(0)][toy(0)]=n;
	q.push(point(0,0));
	while(!q.empty()){
		int x,y,tmp;
		x=q.front().x;
		y=q.front().y;
		q.pop();
		if(m[tox(x)][toy(y)]>=4){
			tmp=m[tox(x)][toy(y)]/4;
			m[tox(x)][toy(y)]-=4*tmp;
			m[tox(x-1)][toy(y)]=tmp;
			q.push(point(x-1,y));
			m[tox(x+1)][toy(y)]=tmp;
			q.push(point(x+1,y));
			m[tox(x)][toy(y-1)]=tmp;
			q.push(point(x,y-1));
			m[tox(x)][toy(y+1)]=tmp;
			q.push(point(x,y+1));
		}
	}
	for(i=0;i<t;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(inmap(x,y))
		  printf("%d\n",m[tox(x)][toy(y)]);
		else
		  printf("0\n");
	}
	return 0;
}
