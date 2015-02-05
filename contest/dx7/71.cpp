#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=100005;
int hx[N],hy[N];
map<pair<int,int>,int> _map;
map<int,int> mx,my;
void init(){
	_map.clear();
	mx.clear();
	my.clear();
	for(int i=0;i<N;++i){
		hx[i]=i;
		hy[i]=i;
	}
}
int main(){
	int n,m,k,W,T;
	int cas=0,x,y,c,q,a,b;
	scanf("%d",&W);
	while(W--){
		init();
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<k;++i){
			scanf("%d%d%d",&x,&y,&c);
			if(mx.find(x)==mx.end())
				mx.insert(make_pair(x,mx.size()+1));
			if(my.find(y)==my.end())
				my.insert(make_pair(y,my.size()+1));
			_map.insert(make_pair(make_pair(mx[x],my[y]),c));
		}
		printf("Case #%d:\n",++cas);
		scanf("%d",&T);
		while(T--){
			scanf("%d%d%d",&q,&a,&b);
			if(q==1){
				if(mx.find(a)!=mx.end() && mx.find(b)!=mx.end())
					swap(hx[mx[a]],hx[mx[b]]);
			}
			else if(q==2){
				if(my.find(a)!=my.end() && my.find(b)!=my.end())
					swap(hy[my[a]],hy[my[b]]);
			}
			else{
				if(mx.find(a)!=my.end() && my.find(b)!=my.end()){
					x=hx[mx[a]];
					y=hy[my[b]];
					if(_map.find(make_pair(x,y))!=_map.end())
						printf("%d\n",_map[make_pair(x,y)]);
					else
						puts("0");
				}
				else
					puts("0");
			}
		}
	}
	return 0;
}
