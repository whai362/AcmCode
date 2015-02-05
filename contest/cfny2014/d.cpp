#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define pb push_back
const int N=100005;
double cnt1[N],cnt2[N],d[N];
struct Dt{
	int to,id;
	Dt(){}
	Dt(int _to,int _id){
		to=_to;
		id=_id;
	}
};
vector<Dt> _map[N];
int n;
int dfs(int r,int fa){
	int ret=0;
	for(int i=0;i<_map[r].size();++i){
		if(_map[r][i].to==fa) continue;
		//cout<<_map[r][i].to<<endl;
		int tmp=dfs(_map[r][i].to,r);
		cnt1[_map[r][i].id]=(double)tmp;
		cnt2[_map[r][i].id]=(double)n-cnt1[_map[r][i].id];
		ret+=tmp;
	}
	return ret+1;
}
int rt;
int du[N];
double c[N];
int main(){
	scanf("%d",&n);
	int u,v,w;
	for(int i=0;i<n-1;++i){
		scanf("%d%d%lf",&u,&v,&d[i]);
		_map[u].pb(Dt(v,i));
		_map[v].pb(Dt(u,i));
		++du[u];
		++du[v];
	}
	for(rt=1;rt<=n;++rt)
		if(du[rt]==1) break;
	dfs(rt,0);
	double ans=0;
	for(int i=0;i<n-1;++i){
		if(cnt1[i]>cnt2[i]){
			swap(cnt1[i],cnt2[i]);
		}
		if(cnt1[i]==1){
			c[i]=(cnt2[i]-1)*cnt2[i]/2;
		}
		else{
			c[i]=(cnt1[i]-1)*cnt1[i]/2*cnt2[i]+(cnt2[i]-1)*cnt2[i]/2*cnt1[i];
		}
		ans+=2.0*c[i]*d[i];
		//cout<<'!'<<cnt1[i]<<' '<<cnt2[i]<<' '<<c[i]<<endl;
	}
	int q;
	scanf("%d",&q);
	int x;
	double y;
	double div=1;
	div=1.0*n*(n-1)*(n-2)/6;
	for(int i=0;i<q;++i){
		scanf("%d%lf",&x,&y);
		ans=ans-2.0*c[x-1]*(d[x-1]-y);
		d[x-1]=y;
		printf("%.9f\n",ans/div);
	}
	return 0;
}
