#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=100009;
int n,m,k,l,f[N];
bool in[N];
vector<int> _map[N];
void init(){
	for(int i=1;i<=n;++i){
		in[i]=1;
		_map[i].clear();
		f[i]=i;
	}
}
int getf(int x){
	if(f[x]!=x) return f[x]=getf(f[x]);
	return x;
}
void gao(int x, int y){
	int fx=getf(x), fy=getf(y);
	if(fx==fy)
		return ;
	f[fx]=fy;
}
int main(){
	int se,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		init();
		for(int i=1;i<=k;++i){
			scanf("%d",&se);
			in[se]=0;
		}
		int u,v;
		for(int i=1;i<=m;++i){
			scanf("%d%d",&u,&v);
			_map[u].push_back(v);
			_map[v].push_back(u);
		}
		scanf("%d",&l);
		bool flag=1;
		if(l<k)
			flag=0;
		int fir,oth,sz;
		scanf("%d",&fir);
		in[fir]=1;
		sz=_map[fir].size();
		for(int i=0;i<sz;++i){
			int ch=_map[fir][i];
			if(in[ch]){
				gao(ch,fir);
			}
		}
		for(int i=2;i<=l;++i){
			scanf("%d",&oth);
			in[oth]=1;
			sz=_map[oth].size();
			for(int i=0;i<sz;++i){
				int ch=_map[oth][i];
				if(in[ch]){
					gao(ch,oth);
				}
			}
			if(getf(oth) != getf(fir)){
				flag=0;
				break;
			}
		}
		int rt=getf(1);
		for(int i=1;i<=n;++i){
			if(getf(i)!=rt) flag=0;
		}
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}
