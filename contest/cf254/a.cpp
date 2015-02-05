#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
const int N=505;
int p[N];
int _map[N][N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&p[i]);
	}
	int u,v,c;
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&u,&v,&c);
		_map[u][v]=_map[v][u]=c;
	}
	double _max=0.0,tmp;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(_map[i][j]){
				tmp=(p[i]+p[j]+0.0)/_map[i][j];
				_max=max(_max,tmp);
			}
		}
	}
	cout<<fixed<<setprecision(16)<<_max<<endl;
	return 0;
}
