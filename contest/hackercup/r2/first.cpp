/*======================================================
# Author: whai
# Last modified: 2016-01-24 01:58
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

char A[N], B[N];

int to_r[N];

void predo(int n) {
	//cout<<A<<endl<<B<<endl;
	memset(to_r, -1, sizeof(to_r));
	for(int i = n - 1; i >= 0; --i) {
		if(A[i] == B[i]) {
			if(i + 1 < n && A[i + 1] == B[i + 1]) {
				to_r[i] = to_r[i + 1];
			} else {
				to_r[i] = i;
			}
		}
	}
	//for(int i = 0; i < n; ++i) {
	//	cout<<to_r[i]<<' ';
	//}
	//cout<<endl;
}

bool ok(int x, int n) {
	int L = to_r[0], R = n - 1;
	int cnt = x;
	for(int i = 0; cnt > 0 && i < n; ++i) {
		if(i == 0 || B[i] != B[i - 1]) {
			--cnt;
			int p = i + 1;
			while(p < n && B[p] == B[p - 1]) ++p;
			L = max(p - 1, to_r[p]);
			i = p - 1;
		}
	}
	cnt = x;
	for(int i = n - 1; cnt > 0 && i >= 0; --i) {
		if(i == n - 1 || B[i] != B[i + 1]) {
			--cnt;
			int p = i - 1;
			while(p >= 0 && B[p] == B[p + 1]) --p;
			R = p + 1;
			i = p + 1;
		}
	}
	//cout<<L<<' '<<R<<endl;
	return L + 1 >= R;
}

void gao(int n) {
	int L = 0, R = n + 1;
	int ans = R;
	while(L < R) {
		//cout<<L<<' '<<R<<endl;
		int mid = (L + R) >> 1;
		if(ok(mid, n)) {
			R = mid;
			ans = min(ans, mid);
		} else {
			L = mid + 1;
		}
	}
	if(ok(L, n)) ans = min(ans, L);
	if(ok(R, n)) ans = min(ans, R);
	cout<<ans<<endl;
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		int n;
		scanf("%d", &n);
		scanf("%s%s", A, B);
		predo(n);
		//cout<<ok(0, n)<<endl;
		//cout<<ok(1, n)<<endl;
		//cout<<ok(2, n)<<endl;
		//cout<<ok(3, n)<<endl;
		//cout<<ok(4, n)<<endl;
		printf("Case #%d: ", ++cas);
		//cerr<<cas<<endl;
		gao(n);
	}
	return 0;
}

