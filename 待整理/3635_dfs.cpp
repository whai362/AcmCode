#include<cstdio>
#include<iostream>
#include<vecotr>
using namespace std;
const int N=1005;
int a[N];
struct Data{
	int v,c;
	Data(){}
	Data(int _v,int _c){
		v=_v;
		c=_c;
	}
};
vector<Data> _map[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);

	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		_map[i].clear();
	}
	int u,v,c;
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&u,&v,&c);
		_map[u].push_back(Data(v,c));
		_map[v].push_back(Data(u,c));
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int s,t,ca;
		scanf("%d%d%d",&s,&t,&ca);
		
	}
}
