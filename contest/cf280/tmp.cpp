#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define Maxn 1005000

int n,m,dx,dy;
int hash[Maxn];
void predo(){
	int x=0,y=0;hash[x]=y;
	for (int i=0;i<n;i++){
		x=(x+dx)%n;y=(y+dy)%n;
		hash[x]=y;
	}
}
int cnt[Maxn];
int main(){
	while (~scanf("%d%d%d%d",&n,&m,&dx,&dy)){
		predo();
		fill(cnt,cnt+n+10,0);
		int x,y;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			cnt[(y+n-hash[x])%n]++;
		}
		int ans=0;
		for (int i=0;i<n;i++)
			if (cnt[ans]<cnt[i]) ans=i;
		printf("0 %d\n",ans);
	}
	return 0;
}
