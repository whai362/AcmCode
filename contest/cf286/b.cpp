#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<time>
using namespace std;
const int N=30005;
const int INF=0x3f3f3f3f;
int mp[N];
map<pair<int,int>,int> tab;
struct Dt{
	int v,p,l;
	Dt(){}
	Dt(int _v,int _p,int _l){
		v=_v;
		p=_p;
		l=_l;
	}
};
int v[N];
int mi[N];
int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	int a;
	memset(mi,0x3f,sizeof(mi));
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		++mp[a];
	}
	v[a]=mp[a];
	for(int i=a-1;i>=0;--i){
		v[i]=v[i+1]+mp[i];
	}
	queue<Dt> q;
	int ans=0;
	ans=max(mp[d],ans);
	mi[d]=min(mi[d],d);
	tab[make_pair(d,d)]=mp[d];
	q.push(Dt(mp[d],d,d));
	while(!q.empty()){
		Dt now=q.front();
		q.pop();
		for(int i=max(1,now.l-1);i<=now.l+1;++i){
			if(now.p+i<=a && now.v+v[now.p+i]>ans && i<mi[now.p]+7){
				mi[now.p]=min(mi[now.p],i);
				if(i==1){
					ans=now.v+v[now.p+i];
					break;
				}
				int getv=now.v+mp[now.p+i];
				int p=now.p+i;
				int lq=tab[make_pair(p,i)];
				if(lq==0 || getv>lq){
					ans=max(getv,ans);
					tab[make_pair(p,i)]=getv;
					q.push(Dt(getv,p,i));
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
