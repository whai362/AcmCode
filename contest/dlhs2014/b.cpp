#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000005;
int in[1005][1005],
	seq[1005][1005];
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
int n,m;

const int M=5000005;
struct Edge{
	int u,v,w;
}edge[M];
bool cmp(Edge x,Edge y){
	return x.w>y.w;
}
int fa[N];
int getFa(int x){
	if(x!=fa[x]) return fa[x]=getFa(fa[x]);
	return x;
}
int kru_min(){
	//cout<<n<<' '<<m<<endl;
	for(int i=0;i<=n;++i) fa[i]=i;
	int ret=0,sel=0;
	for(int i=m-1;i>=0;--i){
		int u=getFa(edge[i].u),v=getFa(edge[i].v);
		if(u==v) continue;
		ret+=edge[i].w;
		fa[v]=u;
		sel++;
	}
	if(sel!=n-1) return -1;
	return ret;
}
int _abs(int x){
	if(x<0) return -x;
	return x;
}
int c,l;
void deal(int x,int y){
	for(int i=0;i<4;++i){
		int tmpx=x+dx[i],
			tmpy=y+dy[i];
		if(tmpx>=0 && tmpx<c && tmpy>=0 && tmpy<l){
			edge[m].u=seq[x][y],edge[m].v=seq[tmpx][tmpy],edge[m].w=_abs(in[x][y]-in[tmpx][tmpy]);
			++m;
		}
	}
}

int main(){
	while(scanf("%d%d",&c,&l)!=EOF){
	n=m=0;
	for(int i=0;i<c;++i)
		for(int j=0;j<l;++j){
			scanf("%d",&in[i][j]);
			seq[i][j]=n++;
		}
	for(int i=0;i<c;++i)
		for(int j=0;j<l;++j){
			deal(i,j);
		}
	sort(edge,edge+m,cmp);
	printf("%d\n",kru_min());
	}
	return 0;
}
