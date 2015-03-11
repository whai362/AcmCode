#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=1e6+5;
const int MOD=2015;
struct Matrix
{
    LL a[3][3];	//
    int n,m;
    Matrix(int _n=0,int _m=0,LL val=0)
    {
        n=_n; m=_m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]=(i==j?val:0);
    }
    void print()
    {
        for(int i=0;i<n;i++,puts(""))
            for(int j=0;j<m;j++)
                cout<<a[i][j]<<' ';
        puts("");
    }
    Matrix operator *(Matrix tmp)
    {
        Matrix ret(n,tmp.m);
        for(int i=0;i<n;i++)
            for(int j=0;j<tmp.m;j++)
                for(int k=0;k<m;k++)
                    ret.a[i][j]=(ret.a[i][j]+a[i][k]*tmp.a[k][j])%MOD;	//
        return ret;
    }
    Matrix operator ^(LL b)
    {
        Matrix ret(n,m,1),base=(*this);
        while(b)
        {
            if(b&1) ret=ret*base;
            b>>=1;
            base=base*base;
        }
        return ret;
    }
};
LL a[N],b[N];
void init(){
	a[0]=1;
	for(int i=1;i<N;++i){
		a[i]=a[i-1]*i%MOD;
		if(i==1) b[i]=0;
		else b[i-1]=a[i-2]*(i-1)*(i-1)%MOD;
	}
	//for(int i=0;i<6;++i){
	//	cout<<a[i]<<' '<<b[i]<<endl;
	//}
	//cout<<endl;
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		Matrix m0=Matrix(1,2),p=Matrix(2,2);
		m0.a[0][0]=a[k]; m0.a[0][1]=b[k];
		p.a[0][0]=k+1; p.a[1][0]=1; p.a[1][1]=k;
		p=p^(n-k-1);
		m0=m0*p;
		//m0.print();
		printf("%I64d\n",m0.a[0][0]);
	}
	return 0;
}
