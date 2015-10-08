/*======================================================
# Author: whai
# Last modified: 2015-10-07 01:37
# Filename: d.cpp
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 2000;
bool is_pri[N];
int pri[N], tot;
void get_pri(int n) {
	tot = 0;
	memset(is_pri, 1, sizeof(bool) * (n + 1));
	is_pri[0] = is_pri[1] = 0;
	for (int i = 2; i < n; ++i)
		if (is_pri[i]) {
			if (n / i < i) break;
			for (int j = i * i; j <= n; j += i) is_pri[j] = false;
		}
	for (int i = 2; i <= n; ++i) if (is_pri[i]) pri[tot++] = i;
}

map<int, int> tab;

LL mul(LL a, LL b, LL m) {
	LL ret = 0;
	a %= m;
	while (b) {
		if (b & 1) ret = (ret + a) % m;
		a = (a + a) % m;
		b >>= 1;
	}
	return ret;
}
LL a_b_MOD_c(LL a, LL b, LL m) {
	LL ret = 1;
	a %= m;
	while (b) {
		if (b & 1) ret = mul(ret, a, m);
		a = mul(a, a, m);
		b >>= 1;
	}
	return ret;
}
bool test(LL n, LL a, LL d) {
	if (n == 2) return true;
	if (n == a) return true;
	if ((n & 1) == 0) return false;
	while (!(d & 1)) d = d >> 1;
	LL t = a_b_MOD_c(a, d, n);
	while ((d != n - 1) && (t != 1) && (t != n - 1)) {
		t = mul(t, t, n);
		d = d << 1;
	}
	return (t == n - 1 || (d & 1) == 1);
}
const int Times = 5;
bool Miller_Rabin(LL n) {
	if (n < 2) return false;
	for (int i = 0; i <= Times; ++i) {
		LL a = rand() % (n - 1) + 1;
		if (!test(n, a, n - 1)) return false;
	}
	return true;
}


int main() {
	get_pri(N);
	for(int i = 0; i < tot; ++i) {
		for(int j = 0; j < tot; ++j) {
			int sum = pri[i] + pri[j];
			tab[sum] = pri[i];
		}
	}
	
	int n;
	cin>>n;
	if(Miller_Rabin(n)) {
		cout<<1<<endl;
		cout<<n<<endl;
	} else if(Miller_Rabin(n - 2)) {
		cout<<2<<endl;
		cout<<2<<' '<<n - 2<<endl;
	} else {
		int a1 = n - 4;
		while(!Miller_Rabin(a1)) a1 -= 2;
		cout<<3<<endl;
		int a2 = tab[n - a1];
		int a3 = n - a1 - a2;
		cout<<a1<<' '<<a2<<' '<<a3<<endl;
	}

	return 0;
}

