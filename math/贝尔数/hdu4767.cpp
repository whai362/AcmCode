#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define LL __int64
LL T[55],B[55];
void get_bell(int n,int MOD){
    B[0]=1;
    B[1]=1;
    T[0]=1;
    for(int i=2;i<=n;++i){
        T[i-1]=B[i-1];
        for(int j=i-2;j>=0;--j)
            T[j]=(T[j]+T[j+1])%MOD;
        B[i]=T[0];
    }
}

//矩阵快速幂
struct Matrix{
	int a[55][55];	//修改处
	int x,y;
};
int n;
Matrix mul(Matrix a,Matrix b,int MOD){
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
Matrix power(Matrix m,int n,int MOD){
	Matrix ret;
	memset(ret.a,0,sizeof(ret.a));
	for(int i=0;i<m.x;++i){		//不是正矩阵，修改
		ret.a[i][i]=1;
	}
	ret.x=ret.y=m.x;	//不是正矩阵，修改
	for(int i=1;i<=n;i<<=1){
		if(i&n){
			ret=mul(ret,m,MOD);
		}
		m=mul(m,m,MOD);
	}
	return ret;
};
void print(Matrix m){
	for(int i=0;i<m.x;++i){
		for(int j=0;j<m.y;++j){
			cout<<m.a[i][j]<<' ';
		}
		cout<<endl;
	}
}
LL a[25],fac[25];
int cnt;
LL deal(int n,int m){
	//cout<<n<<' '<<m<<endl;
	get_bell(50,m);
	//for(int i=1;i<=50;++i){
	//	cout<<i<<' '<<B[i]<<endl;
	//}
	if(n<=50) return B[n];
	Matrix a0;
	a0.x=1; a0.y=50;
	for(int i=0;i<50;++i){
		a0.a[0][i]=B[i+1];
	}
	//print(a0);
	Matrix p;
	p.x=50; p.y=50;
	memset(p.a,0,sizeof(p.a));
	for(int i=0;i<49;++i){
		p.a[i+1][i]=1;
	}
	p.a[50-m][49]=1;
	p.a[50-m+1][49]=1;
	//p.print();
	p=power(p,n-50,m);
	//print(p);
	a0=mul(a0,p,m);
	LL ret=a0.a[0][49];
	//print(a0);
	return ret;
}
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret=Ext_gcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}
LL CRT(LL a[],LL m[],int n){
	LL M=1;
	for(int i=0;i<n;++i) M*=m[i];
	LL ret=0;
	for(int i=0;i<n;++i){
		LL x,y;
		LL tm=M/m[i];
		Ext_gcd(tm,m[i],x,y);
		ret=(ret+tm*x*a[i])%M;
	}
	return (ret+M)%M;
}
void gao(int n,int MOD){
	cnt=0;
	int x=MOD;
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			fac[cnt++]=i;
			while(x%i==0) x/=i;
		}
	}
	if(x>1) fac[cnt++]=x;

	for(int i=0;i<cnt;++i){
		a[i]=deal(n,fac[i]);
		//cout<<fac[i]<<' '<<a[i]<<endl;
	}
	LL ans=CRT(a,fac,cnt);
	printf("%I64d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		gao(n,95041567);
	}
	return 0;
}
