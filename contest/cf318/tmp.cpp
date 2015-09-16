#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (200000+10)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int n;
int edge[MAXN],pre[MAXN],next[MAXN],siz=1;
void addedge(int u,int v) {
	edge[++siz]=v;
	next[siz]=pre[u];
	pre[u]=siz;
}
void addedge2(int u,int v){addedge(u,v),addedge(v,u);}
int degree[MAXN]={0};

bool is_lef[MAXN]={0};
int legs[MAXN]={0};
void dfs(int x,int f)
{
	is_lef[x]=1;
	Forp(x) {
		int v=edge[p];
		if (v==f) continue;
		if (degree[v]<=2) dfs(v,x); //链 
	}
}



int main()
{
//	freopen("E.in","r",stdin);
//	freopen(".out","w",stdout);
	
	MEM(edge) MEM(pre) MEM(next)
	cin>>n;
	For(i,n-1) {
		int u,v;
		scanf("%d%d",&u,&v);
		addedge2(u,v);
		degree[u]++;degree[v]++;
	}
	
	//找链 
	For(i,n) {
		if (degree[i]==1) dfs(i,0);		
	}
	
	
	//找Y型 
	For(i,n) {
		Forp(i) {
			int v=edge[p];
			if (is_lef[v]) ++legs[i]; //一个点连出的链数 
		}
	}
	
	
	bool flag=1;
	
	
	For(i,n) {
		if (is_lef[i]) continue;
		int cnt=0;
		
		Forp(i) {
			int v=edge[p];
			if (!is_lef[v]&degree[v]-min(legs[v],2)>=2)  //这个邻居不是链也不是Y 
				++cnt;
		} 
		
		
		if (cnt>=3) { //只能向两边 
			flag=0;break;
		}
		
	}
	
	
	
	if (flag) puts("Yes");
	else puts("No");
	
	
	return 0;
}
