/*======================================================
# Author: whai
# Last modified: 2015-12-26 18:53
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

const int N = 1e6 + 5;

int a[N];

int in[N][2], out[N][2];

int main() {
	int T;
	cin>>T;

	while(T--) {
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		int n;
		cin>>n;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		in[0][0] = 1;
		out[0][0] = 0;
		for(int i = 0; i < n; ++i) {
			out[i + 1][0] = in[i][1] = in[i][0] ^ a[i];
			in[i + 1][0] = out[i][1] = out[i][0] ^ a[i];
		}
		if(out[n - 1][1]) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}

