#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
#define mp make_pair
const int N=1000005;
struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y){
		x=_x;
		y=_y;
	}
};
char cmd[N];
int n,m,k;
map<pair<int,int>,int> _map,at;

struct Snake{
	int front,rear,length,alive;
	char dir,preDir,ppDir;
	Point body[N];
	void push(Point p){
		Point head=body[front];
		at.insert(mp(mp(head.x,head.y),1));
		--front;
		if(front<0) front+=N;
		body[front]=p;
	}
	void pop(){
		Point tail=body[rear];
		at.erase(mp(tail.x,tail.y));
		--rear;
		if(rear<0) rear+=N;
	}
	//1为食物
	void eat(){
		Point head=body[front];
		if(_map.find(mp(head.x,head.y))!=_map.end() && _map[mp(head.x,head.y)]==1){
			_map.erase(mp(head.x,head.y));
			++rear;
			++length;
			if(rear>=N) rear=0;
			body[rear]=Point(n+1,m+1);
		}
	}
	void move(){
		if(alive==0) return ;
		Point head=body[front];
		switch(dir){
			case 'w':{
						 push(Point(head.x-1,head.y));
						 eat();
						 pop();
						 return ;
					 }
			case 's':{
						 push(Point(head.x+1,head.y));
						 eat();
						 pop();
						 return ;
					 }
			case 'a':{
						 push(Point(head.x,head.y-1));
						 eat();
						 pop();
						 return ;
					 }
			case 'd':{
						 push(Point(head.x,head.y+1));
						 eat();
						 pop();
						 return ;
					 }
					 return ;
		}
	}
	//wwwwsssso
	void dealAbnormal(){
		switch(dir){
			case 'w':{
						 if(preDir=='s') dir='s';
						 ppDir=preDir,preDir=dir;
						 return ;
					 }
			case 's':{
						 if(preDir=='w') dir='w';
						 ppDir=preDir,preDir=dir;
						 return ;
					 }
			case 'a':{
						 if(preDir=='d') dir='d';
						 ppDir=preDir,preDir=dir;
						 return ;
					 }
			case 'd':{
						 if(preDir=='a') dir='a';
						 ppDir=preDir,preDir=dir;
						 return ;
					 }
					 return ;
		}
	}
	//2为石头
	bool die(){
		if(alive==0) return true;
		Point head=body[front];
		if(head.x>=0 && head.x<n && head.y>=0 && head.y<m && (_map.find(mp(head.x,head.y))==_map.end() || _map[mp(head.x,head.y)]==1)){
			if(at.find(mp(head.x,head.y))==at.end()){
				return false;
			}
			else{
				alive=0;
				return true;
			}
		}
		else{
			alive=0;
			return true;
		}
	}
}s,sav;

void save(){
	sav=s;
}
void load(){
	s=sav;
	at.clear();
	if(s.front<=s.rear){
		for(int i=s.front;i<=s.rear;++i)
			at.insert(mp(mp(s.body[i].x,s.body[i].y),1));
	}
	else{
		for(int i=s.front;i<N;++i)
			at.insert(mp(mp(s.body[i].x,s.body[i].y),1));
		for(int i=0;i<=s.rear;++i)
			at.insert(mp(mp(s.body[i].x,s.body[i].y),1));
	}
}

void init(){
	sav.ppDir=sav.preDir='d';
	sav.alive=sav.length=1;
	sav.front=sav.rear=0;
	sav.body[sav.front].x=sav.body[sav.front].y=0;
	_map.clear();
}

void print(){
	int show[30][30];
	memset(show,0,sizeof(show));
	if(s.front<=s.rear){
		for(int i=s.front;i<=s.rear;++i)
			show[s.body[i].x][s.body[i].y]=1;
	}
	else{
		for(int i=s.front;i<N;++i)
			show[s.body[i].x][s.body[i].y]=1;
		for(int i=0;i<=s.rear;++i)
			show[s.body[i].x][s.body[i].y]=1;
	}
	printf("%d %d %d\n",s.length,s.front,s.rear);
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			printf("%d",show[i][j]);
		}
		puts("");
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d%d",&n,&m,&k);
		int u,v,c;
		for(int i=0;i<k;++i){
			scanf("%d%d%d",&u,&v,&c);
			_map.insert(mp(mp(u,v),c));
		}
		scanf("%s",cmd);
		int len=strlen(cmd);
		load();
		for(int i=0;i<len;++i){
			//print();
			if(cmd[i]=='b') save();
			else if(cmd[i]=='l') load();
			else{
				if(cmd[i]=='0') cmd[i]=s.dir;
				s.dir=cmd[i];
				s.dealAbnormal();
				s.move();
				s.die();
			}
		}
		printf("%d %d %d %d\n",s.body[s.front].x,s.body[s.front].y,s.body[s.rear].x,s.body[s.rear].y);
		//print();
	}
	return 0;
}
