/*======================================================
# Author: whai
# Last modified: 2015-10-26 20:39
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
const int N = 1e5 + 5;

LL a[N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%I64d", &a[i]);
	}
	sort(a, a + n);
	LL sum = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(sum <= a[i]) {
			++ans;
			sum += a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

