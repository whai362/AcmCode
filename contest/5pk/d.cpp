#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define N 100005 
struct point{
	int pos,x,y;
}p[N];
int hash[N];
bool cmp1(point p1,point p2){
	return p1.x<p2.x;
}
bool cmp2(point p1,point p2){
	return p1.y<p2.y;
}
int main(){
	int n,m;
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;++i){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(p,p+m,cmp1);
	p[0].pos=1;
	for(i=1;i<m;++i){
		p[i].pos=p[i-1].pos;
		if(p[i].x!=p[i-1].x) ++p[i].pos;
	}
	sort(p,p+m,cmp2);
	int cnt=0,tmp=p[0].y;
	i=0;
	queue<point> q;
	while(i<m && p[i].y==tmp){
		q.push(p[i]);
		if(hash[p[i].pos]==0) ++cnt;
		++hash[p[i].pos];
	}
	while(
}
