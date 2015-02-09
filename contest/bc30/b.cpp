#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=10000007;
#define LL __int64
struct Matrix
{
    LL a[5][5];	//
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
const int N=100005;
int a[N];
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		LL sum=0;
		int _max0=0,_max1=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			if(a[i]>_max0) _max1=_max0,_max0=a[i];
			else if(a[i]>_max1) _max1=a[i];
			sum=(sum+a[i])%MOD;
		}
		//cout<<_max1<<' '<<_max0<<' '<<sum<<endl;
		Matrix a0=Matrix(1,4,0);
		a0.a[0][0]=_max1;
		a0.a[0][1]=_max0;
		a0.a[0][2]=(_max1+_max0)%MOD;
		Matrix p=Matrix(4,4,0);
		p.a[1][0]=p.a[1][2]=p.a[2][1]=p.a[2][2]=p.a[2][3]=p.a[3][3]=1;
		p=p^(k);
		//p.print();
		a0=a0*p;
		//a0.print();
		LL ans=(a0.a[0][3]+sum)%MOD;
		printf("%I64d\n",ans);
		//cout<<(a0.a[0][2]+sum)%MOD<<endl;
	}
	return 0;
}
