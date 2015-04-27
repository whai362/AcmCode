#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
const int N=105;
double sc[N];
bool at[105][105][15];
int st[15][105];
int fk[N],cnt;
void cal1(int n,int q){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=q;++j){
			int cnt=0;
			for(int k=1;k<=n;++k){
				if(at[i][k][j]) fk[cnt++]=k;
			}
			if(cnt){
				sc[i]-=double(n-1);
				for(int k=0;k<cnt;++k){
					sc[fk[k]]+=double(n-1)/cnt;
				}
			}
		}
	}
}
int hao[N],cc;
void cal2(int n,int q){
	for(int i=1;i<=q;++i){
		cc=0;
		for(int j=1;j<=n;++j){
			if(st[i][j]==1) hao[cc++]=j;
			else sc[j]-=double(n-1);
		}
		for(int j=0;j<cc;++j){
			sc[hao[j]]+=(double)(n-cc)*(n-1)/cc;
		}
	}
}
bool lg(double x,double y){
	if(fabs(x-y)<1e-5) return false;
	return x>y;
}
int query(int id,int n){
	int rk=1;
	for(int i=1;i<=n;++i){
		if(lg(sc[i],sc[id])) ++rk;
	}
	printf("%.8f %d\n",sc[id],rk);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,q,c;
		double s;
		scanf("%d%d%lf%d",&n,&q,&s,&c);
		for(int i=1;i<=n;++i)
			sc[i]=s;
		for(int i=0;i<c;++i){
			memset(at,0,sizeof(at));
			int A;
			scanf("%d",&A);
			for(int i=0;i<A;++i){
				int u,v,id;
				scanf("%d%d%d",&u,&v,&id);
				at[v][u][id]=1;
			}
			cal1(n,q);
			for(int i=1;i<=q;++i){
				for(int j=1;j<=n;++j){
					scanf("%d",&st[i][j]);
				}
			}
			cal2(n,q);
			int u;
			scanf("%d",&u);
			for(int i=0;i<u;++i){
				int id;
				scanf("%d",&id);
				query(id,n);
			}
		}
	}
	return 0;
}
