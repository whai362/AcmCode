#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=65;
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
int main(){
	scanf("%d%d%d",&n,&pow,&MOD);
	Matrix ma,mb,ans;
	memset(ma.a,0,sizeof(ma.a));
	ma.x=ma.y=2*n;
	memset(mb.a,0,sizeof(mb.a));
	mb.x=2*n;
	mb.y=n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&ma.a[i][j]);
			mb.a[i][j]=ma.a[i][j];
		}
		ma.a[i+n][i]=1;
		ma.a[i+n][i+n]=1;
	}
	/*for(int i=0;i<ma.x;++i){
		for(int j=0;j<ma.y;++j){
			cout<<ma.a[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<"---"<<endl;
	for(int i=0;i<mb.x;++i){
		for(int j=0;j<mb.y;++j){
			cout<<mb.a[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<"---"<<endl;*/
	ans=power(ma,pow+1);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			int a=ans.a[i+n][j];
			if(i==j) a=(a-1+MOD)%MOD;
			printf("%d%c",a,j+1!=n?' ':'\n');	
		}
	}
	return 0;
}
