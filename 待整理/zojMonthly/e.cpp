#include<cstdio>
#include<cstring>
using namespace std;
bool vis[2005];
int ans,e,n,a[2005][2005],b[2005][2],dir[2005][2];
void dfs(int k,int pre){
	if(vis[k]) return ;
	vis[k]=1;
	for(int i=0;i<n;++i){
		if(a[k][i] && !vis[i]){
			dfs(i,k);
		}
	}
	if(pre==-1) ++ans;
	else{
		dir[e][0]=k;
		dir[e++][1]=pre;
	}
}
int main(){
	int i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;++i)
			scanf("%d%d",&b[i][0],&b[i][1]);
		memset(a,0,sizeof(a));
		e=ans=0;
		for(i=0;i<n-1;++i)
			for(j=i+1;j<n;++j){
				if(b[i][0]==b[j][0] || b[i][1]==b[j][1]){
					a[i][j]=a[j][i]=1;
				}
			}
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;++i) dfs(i,-1);
		printf("%d\n",ans);
		for(i=0;i<e;++i){
			printf("(%d, %d) ",b[dir[i][0]][0],b[dir[i][0]][1]);
			if(b[dir[i][0]][0]==b[dir[i][1]][0]){
				if(b[dir[i][0]][1]<b[dir[i][1]][1]) printf("UP\n");
				else printf("DOWN\n");
			}
			else if(b[dir[i][0]][1]==b[dir[i][1]][1]){
				if(b[dir[i][0]][0]<b[dir[i][1]][0]) printf("RIGHT\n");
				else printf("LEFT\n");
			}
		}
	}
	return 0;
}

