/*======================================================
# Author: whai
# Last modified: 2015-12-08 11:13
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
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const LL INF = 100000000000000LL;

const int N = 1e5 + 5;

LL a[N], b[N];
LL sum = 0;
vector<int> index[N];

LL _abs(LL x) {
    if(x < 0) return -x;
    return x;
}

//1µÄÇé¿ö

LL deal(LL x, LL y, int m) {
    LL ret = sum;
	for(int i = 0; i < index[x].size(); ++i) {
		int p = index[x][i];
		a[p] = y;
		if(p == 1) {
			if(b[p] != b[p + 1]) {
				ret -= _abs(b[p] - b[p + 1]);
			}
		} else if(p == m) {
			if(b[p] != b[p - 1]) {
				ret -= _abs(b[p] - b[p - 1]);
			}
		} else {
			if(b[p] != b[p - 1]) {
				ret -= _abs(b[p] - b[p - 1]);
			}
			if(b[p] != b[p + 1]) {
				ret -= _abs(b[p] - b[p + 1]);
			}
		}
	}
	for(int i = 0; i < index[x].size(); ++i) {
		int p = index[x][i];
		if(p == 1) {
			if(a[p] != a[p + 1]) {
				ret += _abs(a[p] - a[p + 1]);
			}
		} else if(p == m) {
			if(a[p] != a[p - 1]) {
				ret += _abs(a[p] - a[p - 1]);
			}
		} else {
			if(a[p] != a[p - 1]) {
				ret += _abs(a[p] - a[p - 1]);
			}
			if(a[p] != a[p + 1]) {
				ret += _abs(a[p] - a[p + 1]);
			}
		}
	}
	for(int i = 0; i < index[x].size(); ++i) {
		a[index[x][i]] = x;
	}
    return ret;
}

bool used[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%I64d", &a[i]);
		b[i] = a[i];
		index[a[i]].PB(i);
        used[a[i]] = 1;
    }
	sum = 0;
	for(int i = 2; i <= m; ++i) {
		sum += _abs(a[i] - a[i - 1]);
	}

    LL ans = INF;
	
	if(m == 1) {
		puts("0");
		return 0;
	}

    for(int i = 1; i <= n; ++i) {
        if(used[i] == 0) continue;
        int L = 1, R = n;
		LL tmp = INF;
		while(L + 2 < R) {
			int m_l = (L + R) >> 1;
			int m_r = (m_l + R) >> 1;
			LL ans_l = deal(i, m_l, m);
			LL ans_r = deal(i, m_r, m);
			if(ans_l < ans_r) {
				R = m_r;
			} else {
				L = m_l;
			}
			tmp = min(tmp, min(ans_l, ans_r));
		}

        LL sel = (L + R) / 2;
        tmp = min(tmp, deal(i, sel, m));
        tmp = min(tmp, deal(i, L, m));
        tmp = min(tmp, deal(i, R, m));
        ans = min(ans, tmp);
    }
    cout<<ans<<endl;
    return 0;
}
