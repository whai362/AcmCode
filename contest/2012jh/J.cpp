#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define Maxn 1050

int l[Maxn],r[Maxn];
bool v1[Maxn][Maxn],v2[Maxn][Maxn];
char s1[20],s2[20];
int main(){
	int n,m,k,p;
	int x,y;
	while (~scanf("%d%d%d",&n,&m,&k),n|m|k){
		memset(v1,true,sizeof(v1));
		memset(v2,true,sizeof(v2));
		scanf("%d",&p);
		for (int i=1;i<=p;i++){
			scanf("%s%d%s%d",s1,&x,s2,&y);
			if (s1[0]=='c'&&s2[0]=='p'){
				v1[y][x]=false;
			}
			else v2[x][y]=false;
		}
		for (int i=1;i<=m;i++){
			int sum=0;
			for (int j=1;j<=n;j++){
				if (!v1[i][j]) sum++;
			}
			l[i]=sum;
		}
		for (int i=1;i<=m;i++){
			int sum=0;
			for (int j=1;j<=k;j++){
				if (!v2[i][j]) sum++;
			}
			r[i]=sum;
		}
		int ans=n*m*k;
		for (int i=1;i<=m;i++){
			ans-=l[i]*k+r[i]*n-l[i]*r[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
