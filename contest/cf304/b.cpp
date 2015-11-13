/*======================================================
# Author: whai
# Last modified: 2015-10-23 14:36
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 3005;

int a[N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 0;
	for(int i = 1; i < n; ++i) {
		while(a[i] <= a[i - 1]) {
			++a[i];
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}

