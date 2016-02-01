/*======================================================
# Author: whai
# Last modified: 2015-12-25 18:11
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

char a[N], b[N];

int cnt0[N], cnt1[N];

int main() {
	while(cin>>a>>b) {
		int lena = strlen(a);
		int lenb = strlen(b);
		cnt0[0] = cnt1[0] = 0;
		for(int i = 0; i < lenb; ++i) {
			cnt0[i + 1] = cnt0[i];
			cnt1[i + 1] = cnt1[i];
			if(b[i] == '0') {
				++cnt0[i + 1];
			} else {
				++cnt1[i + 1];
			}
		}
		LL ans = 0;
		for(int i = 0; i < lena; ++i) {
			int l = i, r = lenb - (lena - i - 1);
			if(a[i] == '0') {
				ans += cnt1[r] - cnt1[l];
			} else {
				ans += cnt0[r] - cnt0[l];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

