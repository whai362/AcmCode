#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const long long MOD=1000000007;
struct Matrix{
	long long a[2][2];
	int x,y;
};
int n;
Matrix mul(Matrix a,Matrix b){
	Matrix ret;
	for(int i=0;i<a.x;++i){
		for(int j=0;j<b.y;++j){
			long long tmp=0;
			for(int k=0;k<a.y;++k){
				tmp=(tmp+a.a[i][k]*b.a[k][j]%MOD)%MOD;
			}
			ret.a[i][j]=tmp;
		}
	}
	ret.x=a.x;
	ret.y=b.y;
	return ret;
}
Matrix power(Matrix m,int n){
	Matrix ret;
	memset(ret.a,0,sizeof(ret.a));
	for(int i=0;i<2;++i){
		ret.a[i][i]=1;
	}
	ret.x=ret.y=2;
	for(int i=1;i<=n;i<<=1){
		if(i&n){
			ret=mul(ret,m);
		}
		m=mul(m,m);
	}
	return ret;
}
int main(){
	Matrix ans,m0;
	while(scanf("%d",&n) !=EOF){
		++n;
		m0.a[0][0]=1;
		m0.a[0][1]=1;
		m0.a[1][0]=1;
		m0.a[1][1]=0;
		m0.x=m0.y=2;
		ans=power(m0,n);
		printf("%d %lld\n",n-1,ans.a[0][1]);
	}
	return 0;
}
