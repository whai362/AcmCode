/*======================================================
# Author: whai
# Last modified: 2015-10-23 14:46
# Filename: c.cpp
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
#define MP make_pair

const int N = 15;

int a[N], b[N], all[N], all_tot;

LL mul[13];

void predo() {
	mul[0] = 1;
	for(int i = 1; i < 13; ++i) {
		mul[i] = mul[i - 1] * 11;
	}
}

void print(LL x) {
	while(x) {
		cout<<x % 11<<' ';
		x /= 11;
	}
	cout<<endl;
}

set< pair<LL, LL> > used;

int main() {
	predo();
	int n, k1, k2;
	scanf("%d", &n);

	scanf("%d", &k1);
	for(int i = 0; i < k1; ++i) {
		scanf("%d", &a[i]);
		all[all_tot++] = a[i];
	}
	scanf("%d", &k2);
	for(int i = 0; i < k2; ++i) {
		scanf("%d", &b[i]);
		all[all_tot++] = b[i];
	}
	sort(all, all + n);
	LL A = 0;
	for(int i = k1 - 1; i >= 0; --i) {
		a[i] = lower_bound(all, all + n, a[i]) - all + 1;
		A = A * 11 + a[i];
	}
	LL B = 0;
	for(int i = k2 - 1; i >= 0; --i) {
		b[i] = lower_bound(all, all + n, b[i]) - all + 1;
		B = B * 11 + b[i];
	}

	int ans = 0;
	while(k1 && k2 && used.find(MP(A, B)) == used.end()) {
		used.insert(MP(A, B));
		int tmp_a = A % 11; A /= 11; --k1;
		int tmp_b = B % 11; B /= 11; --k2;
		if(tmp_a > tmp_b) {
			A += tmp_b * mul[k1++];
			A += tmp_a * mul[k1++];
		} else {
			B += tmp_a * mul[k2++];
			B += tmp_b * mul[k2++];
		}
		//print(A);
		//print(B);
		++ans;
	}
	if(k1 && k2) {
		puts("-1");
	} else {
		int win = 1;
		if(k1 == 0) win = 2;
		cout<<ans<<' '<<win<<endl;
	}

	return 0;
}

