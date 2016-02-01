/*======================================================
# Author: whai
# Last modified: 2015-12-27 19:30
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

const int N = 2 * 1e5 + 5;
const LL INF = 1e18;
LL a[N];

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		LL minn = INF;
		for(int i = 0; i < n; ++i) {
			scanf("%I64d", &a[i]);
			minn = min(minn, a[i]);
		}
		
		int st = 0;
		for(int i = 0; i < n; ++i) {
			if(a[i] == minn) {
				st = i;
				break;
			}
		}

		int L = st, R;
		
		int maxx = 0;

		for(int i = st + 1; i <= st + n; ++i) {
			if(a[i%n] == minn) {
				R = i;
				maxx = max(maxx, R - L - 1);
				L = i;
			}
		}

		cout<<n * minn + maxx<<endl;
	}
	return 0;
}

