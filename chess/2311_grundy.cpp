#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int W=205;
int w,h;
int vis[W][W];
int grundy(int w,int h){
	if(vis[w][h]!=-1) return vis[w][h];
	set<int> _set;
	for(int i=2;w-i>=2;++i)
		_set.insert(grundy(i,h)^grundy(w-i,h));
	for(int i=2;h-i>=2;++i)
		_set.insert(grundy(w,i)^grundy(w,h-i));
	int ret=0;
	while(_set.count(ret)) ++ret;
	return vis[w][h]=ret;
}
void gao(int w,int h){
	if(grundy(w,h)!=0) puts("WIN");
	else puts("LOSE");
}
int main(){
	int w,h;
	memset(vis,-1,sizeof(vis));
	while(scanf("%d%d",&w,&h)!=EOF){
		gao(w,h);
	}
	return 0;
}
