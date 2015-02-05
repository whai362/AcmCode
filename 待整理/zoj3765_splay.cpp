#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 300005
struct node{
	int par,ch[2],dir;
	int size,num,sta,gcd0,gcd1;
}nd[N];
int cur;
void link(int par,int t,int dir){
	nd[par].ch[dir]=t;
	nd[t].par=par;
	nd[t].dir=dir;
}
void up(int t){
	nd[t].size=nd[nd[t].ch[0]].size+nd[nd[t].ch[1]].size+1;
	nd[t].gcd0=__gcd(nd[nd[t].ch[0]].gcd0,nd[nd[t].ch[1]].gcd0);
	nd[t].gcd1=__gcd(nd[nd[t].ch[0]].gcd1,nd[nd[t].ch[1]].gcd1);
	if(nd[t].sta) nd[t].gcd1=__gcd(nd[t].num,nd[t].gcd1);
	else nd[t].gcd0=__gcd(nd[t].num,nd[t].gcd0);;
}
void rot(int t){	//把节点t往上旋转
	int par=nd[t].par;
	int dir=nd[t].dir;	//判断父亲的方向
	link(nd[par].par,t,nd[par].dir);
	link(par,nd[t].ch[!dir],dir);
	link(t,par,!dir);
	up(par);
}
void splay(int goal,int t){
	while(nd[t].par!=goal){
		int par=nd[t].par;
		if(nd[par].par!=goal){
			if(nd[t].dir==nd[par].dir) rot(par);
			else rot(t);
		}
		rot(t);
	}
	up(t);
}
//寻找以t为根的树中第k个位置的节点
int rank(int k,int t){
	while(true){
		int tmp=nd[nd[t].ch[0]].size+1;
		if(k==tmp) break;
		if(k<tmp) t=nd[t].ch[0];
		else{
			k-=tmp;
			t=nd[t].ch[1];
		}
	}
	return t;
}
//把区间(l,r)的元素集中在一棵子树上（注意是开区间）
int range(int l,int r){
	splay(0,1);
	int rt=rank(l,1),t=rank(r,1);
	splay(0,rt);
	splay(rt,t);
	return t;
}
void insert(int num,int sta,int k){
	int t=range(k+1,k+2);
	nd[++cur].num=num;
	nd[cur].sta=sta;
	nd[cur].size=1;
	link(t,cur,0);
	splay(0,cur);
}
void query(int l,int r,int sta){
	int ans,t=nd[range(l,r+2)].ch[0];
	if(sta==0) ans=nd[t].gcd0;
	else ans=nd[t].gcd1;
	if(ans) printf("%d\n",ans);
	else printf("-1\n");
}
void del(int k){
	int t=range(k,k+2);
	link(t,0,0);
	splay(0,t);	//旋转到根的过程中已经更新了信息。
}
void Modify(int k,int num){
	splay(0,1);
	int t=rank(k+1,1);
	splay(0,t);
	nd[t].num=num;
	up(t);
}
void turn(int k){
	splay(0,1);
	int t=rank(k+1,1);
	splay(0,t);
	nd[t].sta=!nd[t].sta;
	up(t);
}
int main(){
	int n,q;
	int i;
	while(scanf("%d%d",&n,&q)!=EOF){
		cur=2;
		memset(nd,0,sizeof(nd));
		nd[1].size=nd[2].size=1;	//初始化头两个结点
		for(i=0;i<n;++i){
			nd[++cur].size=1;
			scanf("%d%d",&nd[cur].num,&nd[cur].sta);
			if(i==0) link(1,cur,1);
			else link(cur-1,cur,1);
		}
		link(cur,2,1);
		splay(0,2);
		int a,b,c;
		char cmd[10];
		for(i=0;i<q;++i){
			scanf("%s",cmd);
			switch(cmd[0]){
				case 'Q':
					scanf("%d%d%d",&a,&b,&c);
					query(a,b,c);
					break;
				case 'I':
					scanf("%d%d%d",&a,&b,&c);
					insert(b,c,a);
					break;
				case 'D':
					scanf("%d",&a);
					del(a);
					break;
				case 'M':
					scanf("%d%d",&a,&b);
					Modify(a,b);
					break;
				case 'R':
					scanf("%d",&a);
					turn(a);
					break;
			}
		}
	}
	return 0;
}
