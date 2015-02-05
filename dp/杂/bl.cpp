#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=60;
//矩阵快速幂
struct Matrix{
	int a[N][N];	//修改处
	int x,y;
};
int n,pow,MOD;
Matrix mul(Matrix a,Matrix b){
	Matrix ret;
	for(int i=0;i<a.x;++i){
		for(int j=0;j<b.y;++j){
			int tmp=0;	//修改处
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
Matrix add(Matrix a,Matrix b){
	Matrix ret;
	memset(ret.a,0,sizeof(ret.a));
	ret.x=a.x;
	ret.y=a.y;
	for(int i=0;i<a.x;++i){
		for(int j=0;j<a.y;++j){
			ret.a[i][j]=(a.a[i][j]+b.a[i][j])%MOD;
		}
	}
	return ret;
}
int main(){
	scanf("%d%d%d",&n,&pow,&MOD);
	Matrix ans,ma;
	ma.x=ma.y=n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&ma.a[i][j]);
		}
	}
	memset(ans.a,0,sizeof(ans.a));
	ans.x=ans.y=n;
	for(int i=1;i<=pow;++i){
		ans=add(ans,power(ma,i));
	}
	for(int i=0;i<ans.x;++i){
		for(int j=0;j<ans.y;++j){
			cout<<ans.a[i][j]<<' ';
		}
		cout<<endl;
	}

}
