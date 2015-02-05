#include<iostream>
#include<cstdio>
using namespace std;
int mp[1005][1005];
bool gao(int x,int y){
	mp[x][y]|=1;
	if(mp[x][y] && mp[x-1][y] && mp[x-1][y+1] && mp[x][y+1]) return 1;
	if(mp[x][y] && mp[x+1][y] && mp[x+1][y+1] && mp[x][y+1]) return 1;
	if(mp[x][y] && mp[x+1][y] && mp[x+1][y-1] && mp[x][y-1]) return 1;
	if(mp[x][y] && mp[x-1][y] && mp[x-1][y-1] && mp[x][y-1]) return 1;
	return 0;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int ans=0;
	for(int i=0;i<k;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(ans==0 && gao(x,y)){ ans=i+1; }
	}
	printf("%d\n",ans);
	return 0;
}
