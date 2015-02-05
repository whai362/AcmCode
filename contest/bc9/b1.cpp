#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int nn,MOD;
struct Matrix{
	__int64 a[2][2];	//修改处
	int x,y;
};
int n;
Matrix mul(Matrix a,Matrix b){
	Matrix ret;
	for(int i=0;i<a.x;++i){
		for(int j=0;j<b.y;++j){
			__int64 tmp=0;	//修改处
			for(int k=0;k<a.y;++k){
				tmp=(tmp+a.a[i][k]*b.a[k][j]%MOD)%MOD;	//修改处
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
	for(int i=0;i<m.x;++i){		//不是正矩阵，修改
		ret.a[i][i]=1;
	}
	ret.x=ret.y=m.x;	//不是正矩阵，修改
	for(int i=1;i<=n;i<<=1){
		if(i&n){
			ret=mul(ret,m);
		}
		m=mul(m,m);
	}
	return ret;
}
int main(){
	Matrix m0,m1,ans;
	m0.x=m0.y=2;
	m0.a[0][0]=0;
	m0.a[0][1]=1;
	m0.a[1][0]=0;
	m0.a[1][0]=0;
	m1.x=m1.y=2;
	m1.a[0][0]=4;
	m1.a[0][1]=2;
	m1.a[1][0]=2;
	m1.a[1][0]=1;
	scanf("%d%d",&nn,&MOD);
	int t=nn/2;
	cout<<power(m1,t).a[1][0]<<endl;
	ans=mul(m0,power(m1,t));
	//cout<<ans.a[0][0]<<endl;
	if(nn%2){
		ans.a[0][0]=((ans.a[0][0]*2)%MOD+1)%MOD;
	}
	printf("%I64d\n",ans.a[0][0]);
	return 0;
}
