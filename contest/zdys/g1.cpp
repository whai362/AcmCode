#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
struct Node{
	int t,x,y;
}s[3000];
char a[60][60];
int sum[60][60];
bool cmp(Node a,Node b){
	return a.t<b.t;
}
int main(){
	int cases,n,m,f,k;
	scanf("%d",&cases);
	while (cases--){
		scanf("%d%d%d%d",&n,&m,&f,&k);
		memset(a,-1,sizeof(a));
		memset(s,0,sizeof(s));
		for (int i=1;i<=n;i++){
			getchar();
			for (int j=1;j<=m;j++){
				a[i][j]=getchar();
			}
		}
		for (int i=1;i<=k;i++){
			scanf("%d%d%d",&s[i].t,&s[i].x,&s[i].y);
		}
		sort(s+1,s+1+k,cmp);
		int pre=1,tx,ty;
		for (int t=1;t<=f;t++){
			memset(sum,0,sizeof(sum));
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					for (int kk=0;kk<8;kk++){
						tx=i+dx[kk];ty=j+dy[kk];
						if (a[tx][ty]=='1') sum[i][j]++;
					}
				}
			}
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					if (a[i][j]=='1'){
						if (sum[i][j]<2||sum[i][j]>3) a[i][j]='0';
						else a[i][j]='1';
					}
					else if (sum[i][j]==3) a[i][j]='1';
				}
			}
			while (pre<=k&&t==s[pre].t){
				a[s[pre].x][s[pre].y]='2';
				pre++;
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (a[i][j]!='2') putchar(a[i][j]);
				else putchar('X');
			}
			putchar('\n');
		}
	}
	return 0;
}

