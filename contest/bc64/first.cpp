/*======================================================
# Author: whai
# Last modified: 2015-12-10 10:37
# Filename: first.cpp
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

const int N = 1e5 + 5;
int a[N];
int b[N];

int f(int x) {
	return (1890 * x + 143) % 10007;
}

void gao(int n) {
	LL maxx = 0, tmp = 0;
	for(int i = 0; i < n; ++i) {
		tmp += b[i];
		if(tmp < 0) {
			tmp = 0;
		}
		maxx = max(maxx, tmp);
	}
	LL sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += a[i];
	}
	cout<<sum + maxx<<endl;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			b[i] = f(a[i]) - a[i];
		}
		gao(n);
	}
	return 0;
}

