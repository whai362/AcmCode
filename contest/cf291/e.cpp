/*codeforces 514E Darth Vader and Tree
  题意：
  有一棵树，每个节点有n个儿子，给出父亲到每个儿子的距离di，问离祖先距离不超过x的子孙有多少个(子孙包括祖先)对1e9+7取模。
  限制：
  1 <= n <= 1e5; 0 <= x <= 1e9; 1 <= di <= 100
  思路：
  因为di <= 100，所以可以用快速幂来处理这道题，
  大概过程为：先用dp算出前100的答案，剩下的用快速幂来处理。
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1e9+7;
#define LL __int64
struct Matrix
{
    int a[105][105];	//
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
                    ret.a[i][j]=((LL)ret.a[i][j]+(LL)a[i][k]*tmp.a[k][j])%MOD;	//
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
int tab[105];
LL dp[105];
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	int d;
	Matrix m0=Matrix(1,101);
	Matrix p=Matrix(101,101);
	for(int i=0;i<n;++i){
		scanf("%d",&d);
		++tab[d];
		++p.a[100-d][99];
		++p.a[100-d][100];
	}
	dp[0]=1;
	LL sum=1;
	for(int i=1;i<=100;++i){
		for(int j=1;j<=i;++j){
			dp[i]=(dp[i]+dp[i-j]*tab[j])%MOD;
		}
		sum=(sum+dp[i])%MOD;
		m0.a[0][i-1]=dp[i];
	}
	m0.a[0][100]=sum;
	//m0.print();
	for(int i=1;i<100;++i)
		p.a[i][i-1]=1;
	p.a[100][100]=1;
	LL ans=1;
	if(x<100){
		for(int i=0;i<x;++i)
			ans=(ans+m0.a[0][i])%MOD;
		printf("%I64d\n",ans);
	}
	else if(x==100) printf("%d\n",m0.a[0][100]);
	else{
		p=p^((x-100));
		m0=m0*p;
		printf("%d\n",m0.a[0][100]);
	}
	return 0;
}
