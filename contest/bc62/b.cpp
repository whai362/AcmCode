/*======================================================
# Author: whai
# Last modified: 2015-11-14 20:00
# Filename: b.cpp
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

void gao(int x, int k) {
	Matrix a = Matrix(1, 10);
	for(int i = 1; i < 10; ++i) {
		a.a[0][i] = 1;
	}

}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int l, r, k;
		LL ans = (gao(r, k) - gao(l - 1, k) + MOD) % MOD;
		cout<<ans<<endl;
	}
	return 0;
}

