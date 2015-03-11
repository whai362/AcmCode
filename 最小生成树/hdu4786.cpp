#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int cnt;
int fb[N],fa[N];
struct Edge{
	int u,v,w;
}edge[N];
int n,m;
void predo(){
	fb[0]=fb[1]=1;
	cnt=2;
	for(int i=2;fb[i-1]+fb[i-2]<3*N;++i){
		fb[i]=fb[i-1]+fb[i-2];
		++cnt;
	}
	return ;
}
bool cmp(Edge x,Edge y){
	return x.w>y.w;
}
int getfather(int x){
	if (x!=fa[x]) return fa[x]=getfather(fa[x]);
	return fa[x];
}
int Kruskal_Min(){
	for (int i=0;i<=n;i++) fa[i]=i;
	int sum=0;
	int sel=0;
	for (int i=m;i>=1;i--){
		int u=getfather(edge[i].u),v=getfather(edge[i].v);
		if (u==v) continue;
		sum+=edge[i].w;
		fa[v]=u;
		sel++;
	}
	if (sel==n-1) return sum;
	else return -1;
}
int Kruskal_Max(){
	for (int i=0;i<=n;i++) fa[i]=i;
	int sum=0;
	for (int i=1;i<=m;i++){
		int u=getfather(edge[i].u),v=getfather(edge[i].v);
		if (u==v) continue;
		sum+=edge[i].w;
		fa[v]=u;
	}
	return sum;
}

bool work(){
	int Max=Kruskal_Max();
	int Min=Kruskal_Min();
	if (Min==-1) return false;
	int l=lower_bound(fb,fb+cnt,Min)-fb;
	int r=upper_bound(fb,fb+cnt,Max)-fb;
	if(r-1>=l) return true;
	//for (int i=0;i<cnt;i++){
	//	if (Min<=fb[i]&&fb[i]<=Max) return true;
	//}
	return false;
}
void In(int &x){
	char ch;
	while (ch = getchar(),ch < '0' || ch > '9');
	x = ch - '0';
	while (ch = getchar(),ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
}

int main(){
	predo();
	int cases;
	//scanf("%d",&cases);
	In(cases);
	for (int cas=1;cas<=cases;cas++){
		//scanf("%d%d",&n,&m);
		In(n); In(m);
		for (int i=1;i<=m;i++){
			//scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
			In(edge[i].u); In(edge[i].v); In(edge[i].w);
		}
		sort(edge+1,edge+1+m,cmp);
		if (work()) printf("Case #%d: Yes\n",cas);
		else printf("Case #%d: No\n",cas);
	}
	return 0;
}
