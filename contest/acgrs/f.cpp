#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10005
#define M 150005
#define INF 0x3f3f3f3f
struct node{
	int u,v,l,c;
	node(){}
	node(int u,int v,int l,int c):u(u),v(v),l(l),c(c){}
}p[M];
int ansl,ansc,e,n,m,num;
int father[N];
void addnode(int u,int v,int l,int c){
	p[e++]=node(u,v,l,c);
	p[e++]=node(v,u,l,c);
}
int cmp(node a,node b){
	if(a.l!=b.l) return a.l<b.l;
	else return a.c<b.c;
}
void init(){
	int i,u,v,l,c;
	ansl=0;
	ansc=0;
	e=0;
	for(i=0;i<m;++i){
		scanf("%d%d%d%d",&u,&v,&l,&c);
		addnode(u,v,l,c);
	}
	return ;
}
int getFather(int x){
	if(x!=father[x])
	  father[x]=getFather(father[x]);
	return father[x];
}
bool kru(){
	int i,max=0,fu,fv;
	num=0;
	for(i=0;i<=n;++i) father[i]=i;
	for(i=0;i<e;++i){
		//cout<<p[i].u<<' '<<p[i].v<<endl;
		fu=getFather(p[i].u);
		fv=getFather(p[i].v);
		if(fu==fv) continue;
		father[fv]=fu;
		ansl+=p[i].l;
		ansc+=p[i].c;
		++num;
		//cout<<num<<endl;
		if(num==n-1) return true;
	}
	return false;
}
int main(){
	int i,max;
	while(scanf("%d%d",&n,&m)!=EOF){
	init();
	sort(p,p+e,cmp);
	if(kru()){
		printf("%d %d\n",ansl,ansc);
	}
	else{
		printf("-1 -1\n");
	}
	}
	return 0;
}

