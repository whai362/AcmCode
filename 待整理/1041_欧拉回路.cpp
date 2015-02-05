#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct Data{
	int y,z;
	Data(){}
	Data(int _y,int _z){
		y=_y;
		z=_z;
	}
};
const int N=2000,
	  M=2*N;
bool vis[N],jvis[M];
int cnt;
int ans[M],d[M];
vector<Data> _map[M];
void dfs(int rt){
	int sz=_map[rt].size();
	jvis[rt]=true;
	for(int i=0;i<sz;++i){
		if(!vis[_map[rt][i].z]){
			vis[_map[rt][i].z]=true;
			dfs(_map[rt][i].y);
			ans[cnt++]=_map[rt][i].z;
		}
	}
}
bool ok(int rt){
	dfs(rt);
	for(int i=0;i<M;++i){
		if(!jvis[i] && _map[i].size()>0){
			return false;
		}
	}
	return true;
}
int main(){
	int x,y,z,rt;
	while(true){
		for(int i=0;i<M;++i){
			_map[i].clear();
		}
		cnt=0;
		memset(vis,0,sizeof(vis));
		memset(jvis,0,sizeof(jvis));
		memset(d,0,sizeof(d));
		scanf("%d%d",&x,&y);
		if(x || y){
			rt=x;
			scanf("%d",&z);
			++d[x];
			++d[y];
			_map[x].push_back(Data(y,z));
			_map[y].push_back(Data(x,z));
			while(scanf("%d%d",&x,&y) && (x || y)){
				rt=x;
				scanf("%d",&z);
				++d[x];
				++d[y];
				_map[x].push_back(Data(y,z));
				_map[y].push_back(Data(x,z));
			}
			if(ok(rt)){
				int flag=1;
				for(int i=0;i<M;++i){
					if(d[i]%2){
						flag=0;
						break;
					}
				}
				if(flag){
					for(int i=cnt-1;i>=0;--i){
						cout<<ans[i]<<endl;
					}
				}
				else{
					printf("Round trip does not exist.\n");
				}
			}
			else{
				printf("Round trip does not exist.\n");
			}
		}
		else{
			break;
		}
	}
	return 0;
}
