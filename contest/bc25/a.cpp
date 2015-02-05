#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define pb push_back
const int N=105;
int in[N];
int n,m;
vector<int> mp[N];
bool tp(){
	int cnt=0;
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(in[i]==0){ q.push(i); ++cnt; }
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<mp[now].size();++i){
			int ch=mp[now][i];
			--in[ch];
			if(in[ch]==0){ q.push(ch); ++cnt; }
		}
	}
	if(cnt==n) return true;
	return false;
}
void gao(){
	if(tp()) puts("YES");
	else puts("NO");
}
void init(){
    for(int i=0;i<=n;++i){
        mp[i].clear();
    }
    memset(in,0,sizeof(in));
}
int main(){
    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            mp[b].pb(a);
			++in[a];
        }
        gao();
    }
    return 0;
}
