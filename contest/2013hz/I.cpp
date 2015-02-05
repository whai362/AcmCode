#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define Maxn 50
struct Node {
	int x,y,xx,yy,dis;
}ans;
char st[Maxn][Maxn];
int main(){
	int n,m;
	while (~scanf("%d%d",&n,&m)){
		if (n==0&&m==0) break;
		for (int i=0;i<n;i++)
			scanf("%s",st[i]);
		ans.dis=1000;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (st[i][j]=='H'){
					for (int ii=0;ii<n;ii++){
						for (int jj=0;jj<m;jj++){
							if (st[ii][jj]=='C'){
								int dis=abs(i-ii)+abs(j-jj);
								if (dis<ans.dis){
									ans.x=i;ans.y=j;
									ans.xx=ii;ans.yy=jj;
									ans.dis=dis;
								}
							}
						}
					}
				}
			}
		}
		printf("%d %d %d %d\n",ans.x,ans.y,ans.xx,ans.yy);
	}
	return 0;
}
