/*======================================================
# Author: whai
# Last modified: 2016-01-31 23:22
# Filename: e.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int MOD = 1000000007;

struct Matrix {
    int a[105][105]; //
    int n, m;
    Matrix(int _n = 0, int _m = 0, LL val = 0) {
        n = _n; m = _m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = (i == j ? val : 0);
    }
    void print() {
        for (int i = 0; i < n; i++, puts(""))
            for (int j = 0; j < m; j++)
                cout << a[i][j] << ' ';
        puts("");
    }
    Matrix operator *(Matrix tmp) {
        Matrix ret(n, tmp.m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < tmp.m; j++)
                for (int k = 0; k < m; k++)
                    ret.a[i][j] = ((LL)ret.a[i][j] + (LL)a[i][k] * tmp.a[k][j]) % MOD; //
        return ret;
    }
    Matrix operator ^(LL b) {
        Matrix ret(n, m, 1), base = (*this);
        while (b) {
            if (b & 1) ret = ret * base;
            b >>= 1;
            base = base * base;
        }
        return ret;
    }
};

int cnt[10];
int main() {
	int n, b, k, x;

	while(scanf("%d%d%d%d", &n, &b, &k, &x) != EOF) {
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			++cnt[x];
		}
		Matrix a0(1, x);
		for(int i = 0; i < 10; ++i) {
			a0.a[0][i % x] += cnt[i];
		}
		//a0.print();
		Matrix m(x, x);
		for(int i = 0; i < x; ++i) {
			for(int j = 0; j < x; ++j) {
				//j x ways to i;
				int tmp = 0;
				for(int l = 0; l < 10; ++l) {
					if((j * 10 + l) % x == i) {
						tmp += cnt[l];
					}
				}
				m.a[j][i] = tmp;
			}
		}
		//m.print();
		a0 = a0*(m^(b - 1));
		//a0.print();
		cout<<a0.a[0][k]<<endl;
	}

	return 0;
}

