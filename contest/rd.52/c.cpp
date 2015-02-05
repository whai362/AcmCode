#include<cstdio>
using namespace std;
bool m[1001][1001];
int cnt=0,n,ans[1001][3];
void gao(int x,int y){
	static int i=1,j=0;
	int k,tmp;
	while(i<n && j<n-1){
		if(!m[i][j]) break;
		++i,++j;
 	}
	if(x!=i){
		ans[cnt][0]=1,ans[cnt][1]=x+1,ans[cnt++][2]=i+1;
		for(k=0;k<n;++k){
			if(m[x][k]!=m[i][k]){
				tmp=m[x][k];
				m[x][k]=m[i][k];
				m[i][k]=tmp;
			}
		}
	}
	if(y!=j){
		ans[cnt][0]=2,ans[cnt][1]=y+1,ans[cnt++][2]=j+1;
		for(k=0;k<n;++k){
			if(m[k][y]!=m[k][j]){
				tmp=m[k][y];
				m[k][y]=m[k][j];
				m[k][j]=tmp;
			}
		}
	}
}
int main(){
	int i,j,x,y;
	scanf("%d",&n);
	for(i=0;i<n-1;++i){
		scanf("%d%d",&x,&y);
		m[x-1][y-1]=1;
	}
	for(i=0;i<n;++i){
		for(j=i;j<n;++j){
			while(m[i][j]) gao(i,j);
		}
	}
	for(i=0;i<n;++i){
		for(j=i;j<n;++j){
			while(m[i][j]) gao(i,j);
		}
	}
	printf("%d\n",cnt);
	for(i=0;i<cnt;++i){
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}
