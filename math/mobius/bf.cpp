/*======================================================
# Author: whai
# Last modified: 2015-11-03 12:13
# Filename: bf.cpp
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

const int N = 10005;

int a[N];

bool in[N];
vector<int> b;

void gao(int id) {
	if(in[id]) {
		sort(b.begin(), b.end());
		int x = a[id];
		b.erase(lower_bound(b.begin(), b.end(), x));
		in[id] = 0;
	} else {
		int x = a[id];
		b.push_back(x);
		in[id] = 1;
	}
	int cnt = 0;
	for(int i = 0; i < b.size(); ++i) {
		for(int j = i + 1; j < b.size(); ++j) {
			if(__gcd(b[i], b[j]) == 1) {
				++cnt;
			}
		}
	}
	cout<<cnt<<endl;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		gao(x);
	}

	return 0;
}
