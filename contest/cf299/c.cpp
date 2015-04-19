/*codeforces 536 c Tavas and Pashmaks
  题意：
  在一个运动比赛中有两种跑道，现在有n个选手，给出每个选手的在两种跑道上的速度，(ui,vi)，求哪些选手可能赢得比赛。
  限制：
  1 <= n <= 2*1e5
  思路：
  维护一个类似凸包的一段。
 */
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define PB push_back
const int N=2*1e5+5;
struct Dt{
	double x,y;
	int id;
	Dt(){}
	Dt(int _x,int _y,int _id){
		x=_x;
		y=_y;
		id=_id;
	}
	bool operator < (const Dt t) const{
		if(x==t.x){
			return y<t.y;
		}
		return x<t.x;
	}
}a[N];
priority_queue<Dt> q;
int ans[N],cnt=0;
vector<int> tab[N];
double xl[N];
void gao(Dt now){
	if(cnt==0){
		tab[cnt].PB(now.id);
		ans[cnt++]=now.id;
		return ;
	}
	double tmp;
	int pre=ans[cnt-1];
	if(now.y==a[pre].y){
		if(now.x==a[pre].x){
			tab[cnt-1].PB(now.id);
			return ;
		}
		return ;
	}
	while(cnt>1){
		pre=ans[cnt-1];

		tmp=(now.x-a[pre].x)*now.y*a[pre].y/((a[pre].y-now.y)*a[pre].x*now.x);
		if(tmp<xl[pre]){
			tab[cnt-1].clear();
			--cnt;
		}
		else break;
	}
	pre=ans[cnt-1];
	tmp=(now.x-a[pre].x)*now.y*a[pre].y/((a[pre].y-now.y)*a[pre].x*now.x);
	xl[now.id]=tmp;
	tab[cnt].PB(now.id);
	ans[cnt++]=now.id;
}

int main(){
	int n;
	double u,v;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%lf%lf",&u,&v);
		a[i]=Dt(u,v,i);
		q.push(Dt(u,v,i));
	}
	double _max=0;
	while(!q.empty()){
		while(!q.empty() && q.top().y<_max){
			q.pop();
		}
		if(q.empty()) break;
		Dt now=q.top();
		q.pop();
		gao(now);
		_max=max(_max,now.y);
	}
	int cc=0;
	for(int i=0;i<cnt;++i){
		for(int j=0;j<tab[i].size();++j){
			ans[cc++]=tab[i][j];

		}
	}
	
	sort(ans,ans+cc);
	for(int i=0;i<cc;++i){
		printf("%d%c",ans[i]+1,i==cc-1?'\n':' ');
	}
	return 0;
}
