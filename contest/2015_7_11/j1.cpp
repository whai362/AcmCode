#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
#define LL __int64
const int N=25;
LL C[N][N];
LL get_p(int x,int y,int n,int m){
	int A[2],B[2],C[2],D[2];
	A[0]=x*y, A[1]=(x+1)*(y+1);
	B[0]=(n-1-x)*(m-1-y), B[1]=(n-x)*(m-y);
	C[0]=x*(m-1-y), C[1]=(x+1)*(m-y);
	D[0]=(n-1-x)*y, D[1]=(n-x)*(y+1);

	LL ret = (LL)A[0]*B[1] + (LL)B[0]*A[1] + (LL)C[0]*D[1] + (LL)D[0]*C[1];
	ret += (LL)x*(n-x)*m + (LL)(n-1-x)*(x+1)*m + (LL)y*(m-y)*n + (LL)(m-1-y)*(y+1)*n;
	ret += (LL)n*m;
	return ret;
}

double get_qw(double p,int k){
	return 1.0-pow(1-p,k);
}

void gao(int n,int m,int k){
	double ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			double p=(double)get_p(i,j,n,m)/((double)n*n*m*m);
			ans+=get_qw(p,k);
		}
	}
	printf("%.0f\n",ans);
}
int main(){
	int T;
	int n,m,k;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		printf("Case #%d: ",++cas);
		gao(n,m,k);
	}
	return 0;
}
