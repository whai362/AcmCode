#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL __int64
const int MOD = 1000000007;

struct Matrix
{
    LL a[55][55];	//
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

const int N = 55;

int a[N];

int ok(int x, int y) {
	int A[15], A_cnt = 0;
	int B[15], B_cnt = 0;
	int bei = 100;
	while(x / bei) {
		A[A_cnt++] = x % bei;
		bei *= 10;
	}
	if(x > 9) A[A_cnt++] = x % bei;

	bei = 1;
	while(y / (bei * 10)) {
		B[B_cnt++] = y / bei;
		bei *= 10;
	}
	//for(int i = 0; i < A_cnt; ++i) {
	//	cout<<A[i]<<' ';
	//}
	//cout<<endl;
	//for(int i = 0; i < B_cnt; ++i) {
	//	cout<<B[i]<<' ';
	//}
	//cout<<endl;
	//int ret = 0;
	for(int i = 0; i < A_cnt; ++i) {
		for(int j = 0; j < B_cnt; ++j) {
			if(A[i] == B[j]) return 1;
		}
	}
	return 0; 
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, p;
		scanf("%d%d", &n, &p);
		
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);

		sort(a, a+n);
		n = unique(a, a+n) - a;

		Matrix m0 = Matrix(1, n);
		for(int i = 0; i < m0.m; ++i)
			m0.a[0][i] = 1;
		Matrix m = Matrix(n, n);
		//cout<<ok(121, 213)<<endl;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				m.a[j][i] = ok(a[j], a[i]);
			}
		}
		//m.print();
		m = m ^ (p - 1);
		m0 = m0 * m;
		LL ans = 0;
		for(int i = 0; i < m0.m; ++i) {
			ans = (ans + m0.a[0][i]) % MOD;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
