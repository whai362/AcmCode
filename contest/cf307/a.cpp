/*======================================================
# Author: whai
# Last modified: 2015-10-20 17:03
# Filename: a.cpp
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

const int N = 2005;

int a[N];
int b[N];
void gao(int n) {
	sort(b, b + n);

	for(int i = 0; i < n; ++i) {
		a[i] = upper_bound(b, b + n, a[i]) - b;
		a[i] = n - a[i] + 1;
	}
	for(int i = 0; i < n; ++i) {
		cout<<a[i]<<' ';
	}
	cout<<endl;
}

int main() {
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	gao(n);

	return 0;
}
