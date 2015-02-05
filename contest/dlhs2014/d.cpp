#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
#define LL long long
int tr[1005][55][4];
int ip[1005][4];
int su[55][4];
int ans[55];
map<LL,int> _map;
int main(){
	int n,m;
	char ch;
	while(scanf("%d%d",&n,&m)!=EOF){
		_map.clear();
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;++i)
			scanf("%d %c %d %c %d %c %d",&ip[i][0],&ch,&ip[i][1],&ch,&ip[i][2],&ch,&ip[i][3]);
		for(int i=0;i<m;++i)
			scanf("%d %c %d %c %d %c %d",&su[i][0],&ch,&su[i][1],&ch,&su[i][2],&ch,&su[i][3]);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				LL tmp=0;
				for(int k=0;k<4;++k){
					//cout<<ip[i][k]<<' ';
					tmp=tmp*1000+(ip[i][k]&su[j][k]);
				}
				//cout<<endl;
				//cout<<tmp<<endl;
				++_map[tmp];
				if(_map[tmp]==1) ++ans[j];
			}
		}
		for(int i=0;i<m;++i){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
