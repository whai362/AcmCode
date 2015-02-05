#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
bool vis[30];
int in[30],out[30];
vector<int> _map[30];
void dfs(int rt){
	vis[rt]=true;
	int sz=_map[rt].size();
	for(int i=0;i<sz;++i){
		if(!vis[_map[rt][i]]){
			dfs(_map[rt][i]);
		}
	}
}
bool conn(int st){
	dfs(st);
	for(int i=0;i<26;++i){
		if(!vis[i] && _map[i].size()>0){
			return false;
		}
	}
	return true;
}
int main(){
	int n,cnt,cntA,cntB,T;
	char str[1005];
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	cnt=cntA=cntB=0;
	memset(vis,0,sizeof(vis));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	for(int i=0;i<26;++i){
		_map[i].clear();
	}
	for(int i=0;i<n;++i){
		scanf("%s",str);
		++out[str[0]-'a'];
		++in[str[strlen(str)-1]-'a'];
		_map[str[0]-'a'].push_back(str[strlen(str)-1]-'a');
		_map[str[strlen(str)-1]-'a'].push_back(str[0]-'a');
	}
	if(conn(str[0]-'a')){
		for(int i=0;i<26;++i){
			if(in[i]!=out[i]){
				++cnt;
				if(in[i]-out[i]==1){
					++cntA;
				}
				if(in[i]-out[i]==-1){
					++cntB;
				}
			}
		}
		if(cnt==0 || (cnt==2 && cntA==1 && cntB==1)){
			printf("Ordering is possible.\n");
		}
		else{
			printf("The door cannot be opened.\n");
		}
	}
	else{
		printf("The door cannot be opened.\n");
	}
	}
	return 0;
}
