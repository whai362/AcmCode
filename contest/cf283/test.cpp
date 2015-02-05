#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int mod = 1e9+7;
const int MAXN = 35;

int tmp[MAXN],K;
struct Matrix
{
	int a[MAXN][MAXN];
	Matrix trans(int x)
	{
		Matrix c;
		for(int i=0;i<K;++i)
			tmp[i]=(i+x)%K;
		tmp[K]=K;
		for(int i=0;i<=K;++i)
			for(int j=0;j<=K;++j)
				c.a[tmp[i]][tmp[j]]=a[i][j];
		return c;
	}
	Matrix operator * (const Matrix b) const 
	{
		Matrix res;
		for(int i=0;i<=K;++i)
			for(int j=0;j<=K;++j)
				res.a[i][j]=0;
		for(int i=0;i<=K;++i)
			for(int j=0;j<=K;++j)
				for(int l=0;l<=K;++l)
					res.a[i][j]=(res.a[i][j]+1LL*a[i][l]*b.a[l][j])%mod;
		return res;
	}
	void prt()
	{
		for(int i=0;i<=K;++i,printf("\n"))
			for(int j=0;j<=K;++j)
				printf("%d ",a[i][j]);
		puts("");
	}
}f[70][MAXN],ans;

long long n;
void init()
{
	cin>>n>>K;
	for(int i=0;i<=K;++i)
		ans.a[i][i]=f[0][0].a[i][i]=f[0][0].a[i][0]=1;
}
void work()
{
	int T(0);
	long long pow(1);
	for(;;)
	{
		for(int i=1;i<K;++i)
			f[T][i]=f[T][i-1]*(f[T][0].trans(i));
		f[T+1][0]=f[T][K-1];
		if(pow>n/K) break;
		++T;
		pow*=1LL*K;
	}
	int add(0);
	for(;T>=0;--T,pow/=1LL*K)
	{
		if(n/pow) ans=ans*(f[T][n/pow-1].trans(add));
		add=(add+n/pow)%K;
		n%=pow;
	}
	long long sum(0);
	for(int i=0;i<=K;++i)
		sum+=ans.a[K][i];
	cout<<(sum%mod)<<endl;
}
int main()
{
	K=4;
	Matrix a,b;
	for(int i=0;i<K;++i){
		for(int j=0;j<K;++j){
			cin>>a.a[i][j];
		}
	}
	for(int i=0;i<K;++i){
		for(int j=0;j<K;++j){
			cin>>b.a[i][j];
		}
	}
	a=a*b;
	cout<<endl;
	a.prt();
	//init();
	//work();
	return 0;
}
