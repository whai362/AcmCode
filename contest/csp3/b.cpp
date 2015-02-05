/*floyd算法*/
/*人口参数m,n,邻接矩阵*/
/*出口参数p[st][en]*/ 
#include<stdio.h>
#include<string.h>
#define Min(x,y) (((x)<(y))?(x):(y))
#define inf 0x3f3f3f3f
long long m,n,p[205][205];
int main(){
	long long i,j,k,u,v,c;
	while(scanf("%lld",&n)!=EOF){
	++n;
	for(i=1;i<=n;++i){	//注意初始化的方式*/ 
		for(j=1;j<=n;++j){
			scanf("%lld",&p[i][j]);
		}
	}
	for(k=1;k<=n;++k)
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j) p[i][j]=Min(p[i][j],p[i][k]+p[k][j]);
	printf("%lld",p[1][2]);
	for(long long j=3;j<=n;++j){
		printf(" %lld",p[1][j]);
	}
	puts(" ");
	}
	return 0;
}

