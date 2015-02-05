/*cf284div1e
  题意：给出7个阶梯的宽度wi，阶梯的高度是一定的，阶梯排在一起形成一个图案，现在在图案内部加入一些横线或竖线使得每个方格都不被线包围，问有多少种方法。
  限制：0 <= wi <= 1e5
  思路：dp,快速幂
  文字好难表述。。。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int MOD=1000000007;
struct Matrix{
	LL a[1300][1300];
	int x,y;
};
int n;
Matrix mul(Matrix a,Matrix b){
	Matrix ret;
	for(int i=0;i<a.x;++i){
		for(int j=0;j<b.y;++j){
			int tmp=0;
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
	for(int i=0;i<m.x;++i){
		ret.a[i][i]=1;
	}
	ret.x=ret.y=m.x;
	for(int i=1;i<=n;i<<=1){
		if(i&n){
			ret=mul(ret,m);
		}
		m=mul(m,m);
	}
	return ret;
}

int a[7];
Matrix m0,p;
void print(Matrix p){
	for(int i=0;i<p.x;++i){
		for(int j=0;j<p.y;++j){
			cout<<p.a[i][j]<<' ';
		}
		cout<<endl;
	}
}
int main(){
	for(int i=0;i<7;++i)
		scanf("%d",&a[i]);
	m0.x=1;
	m0.y=2;
	m0.a[0][0]=0;
	m0.a[0][1]=1;

	//print(m0);
	for(int i=0;i<7;++i){
		p.x=p.y=(1<<(i+1));
		for(int j=0;j<p.y;++j){
			for(int k=0;k<p.x;++k){
				int cnt=0;
				for(int l=0;l<(1<<i);++l){
					int flag=1;
					if(i==0 && j==1 && k==1)
						flag=0;
					for(int i1=0;i1<=i;++i1){
						if((j & (1<<i1)) && (k & (1<<i1))){
							if(i1==0 && (l & (1<<i1))){
								flag=0;
								break;
							}
							if(i1==i && (l & (1<<(i1-1)))){
								flag=0;
								break;
							}
							if(i1>0 && i1<i && (l & (1<<i1)) && (l & (1<<(i1-1)))){
								flag=0;
								break;
							}
						}
					}
					cnt+=flag;
				}
				p.a[k][j]=cnt;
			}
		}
		//if(i==1){
		//	print(p);
		//}
		m0=mul(m0,power(p,a[i]));
		int add=(1<<(i+1));
		for(int j=0;j<m0.y;++j){
			m0.a[0][j+add]=m0.a[0][j];
			m0.a[0][j]=0;
		}
		m0.y*=2;
	}
	cout<<m0.a[0][m0.y-1]<<endl;
	return 0;
}
