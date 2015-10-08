/*======================================================
# Author: whai
#
# Last modified: 2015-10-06 12:58
#
# Filename: a.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

const int MOD = 1000000007;

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

struct Matrix {
    int a[5][5]; //
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
                for (int k = 0; k < m; k++) {
					if(a[i][k] == 0 || tmp.a[k][j] == 0) continue;
                    ret.a[i][j] = ((ret.a[i][j] + (LL)a[i][k] * tmp.a[k][j]) % MOD + MOD) % MOD; //
				}
        return ret;
    }
    Matrix operator ^(LL b) {
        Matrix ret(n, m, 1), base = (*this);
        while (b) {
            if (b & 1LL) ret = ret * base;
            b >>= 1;
            base = base * base;
        }
        return ret;
    }
};

void In(int &x) {
	char c; x = 0; c = getchar();
	int sign = 1;
	while (!(c >= '0' && c <= '9' || c == '-')) c = getchar();
	if (c == '-') sign = -1, c = getchar();
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	x *= sign;
}

void In(LL &x) {
	char c; x = 0; c = getchar();
	int sign = 1;
	while (!(c >= '0' && c <= '9' || c == '-')) c = getchar();
	if (c == '-') sign = -1, c = getchar();
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	x *= sign;
}

void Out(int x) {
	if (x < 0) { x = -x; putchar('-');}
	if (x > 9)
		Out(x / 10);
	putchar(x % 10 + '0');
}

void Out(LL x) {
	if (x < 0) { x = -x; putchar('-');}
	if (x > 9)
		Out(x / 10);
	putchar(x % 10 + '0');
}



void gao(LL n) {
	if(n == 1) {
		puts("6");
		return ;
	}
	Matrix a0 = Matrix(1, 3);
	a0.a[0][0] = 6;
	a0.a[0][1] = 35;
	a0.a[0][2] = 41;
	//a0.print();
	Matrix p = Matrix(3, 3);
	p.a[0][0] = p.a[2][0] = p.a[2][1] = 0;
	p.a[1][0] = p.a[2][2] = 1;
	p.a[1][1] = p.a[1][2] = 6;
	p.a[0][1] = p.a[0][2] = -1;
	//p.print();
	p = p ^ (n - 2);
	a0 = a0 * p;
	Out(a0.a[0][2]);
	puts("");
}

const int BZ = 120 * (1 << 20);
char Buf[BZ + 1], *buf = Buf;

template <class T>
inline void scan(T &a) {
	for (a = 0; *buf < '0' || *buf > '9'; ++buf);
	while (*buf >= '0' && *buf <= '9') {
		a = a * 10 + (*buf - '0');
		++buf;
	}
}


//a[n] = 6 * a[n - 1] - a[n - 2]
int main() {
	fread(Buf, 1, BZ, stdin);
	int T;
	scan(T);
	while(T--) {
		LL n;
		scan(n);
		n %= (MOD - 1);
		gao(n);
	}
	return 0;
}

