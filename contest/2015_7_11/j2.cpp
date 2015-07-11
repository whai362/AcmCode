#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL __int64
const int N=25;
LL C[N][N];
double get_p(int x,int y,int n,int m){
	int A[2],B[2],C[2],D[2];
	A[0]=x*y, A[1]=(x+1)*(y+1);
	B[0]=(n-1-x)*(m-1-y), B[1]=(n-x)*(m-y);
	C[0]=x*(m-1-y), C[1]=(x+1)*(m-y);
	D[0]=(n-1-x)*y, D[1]=(n-x)*(y+1);

	int ret = A[0]*B[1] + B[0]*A[1] + C[0]*D[1] + D[0]*C[1];
	ret += x*(n-x)*m + (n-1-x)*(x+1)*m + y*(m-y)*n + (m-1-y)*(y+1)*n;
	ret += n*m;
	return (double)ret/(n*m*n*m);
}

void init(){
	for(int i=0;i<N;++i){
		C[i][0]=C[i][i]=1;
	}
	for(int i=2;i<N;++i){
		for(int j=1;j<i;++j){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
}

double get_qw(double p,int k){
	double ret=0;
	for(int i=1;i<=k;++i){
		ret+=(double)C[k][i]*pow(p,i)*pow(1-p,k-i);
	}
	return ret;
}

void gao(int n,int m,int k){
	double ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			double p=get_p(i,j,n,m);
			double qw=get_qw(p,k);
			//cout<<p<<' ';
			ans+=qw;
		}
		//cout<<endl;
	}
	printf("%.0f\n",ans);
}
int main(){
	int T;
	int n,m,k;
	scanf("%d",&T);
	int cas=0;
	init();
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		printf("Case #%d: ",++cas);
		gao(n,m,k);
	}
	return 0;
}
