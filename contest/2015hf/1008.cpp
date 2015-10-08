#include <iostream>
#include <cstdio>
using namespace std;

int S[33];

void deal(int c, int cnt, int len) {
	int tmp[33];
	for(int i = 0; i <= len; ++i) {
		tmp[i] = S[i];
	}
	if(c > cnt) {
		int nd = c - cnt;
		for(int i = 0; nd > 0 && i <= len; ++i) {
			if(tmp[i] == 0) {
				tmp[i] = 1;
				--nd;
			}
		}
	} else if(c == cnt) {
		int use = 0;
		int pd1 = 0;
		for(int i = 0; i <= len; ++i) {
			if(tmp[i] == 1) {
				pd1 = 1;
				tmp[i] = 0;
				++use;
			}
			if(pd1 && tmp[i] == 0) {
				tmp[i] = 1;
				break;
			}
		}
		--use;
		for(int i = 0; use > 0 && i <= len; ++i) {
			if(tmp[i] == 0) {
				tmp[i] = 1;
				--use;
			}
		}
	} else if(c < cnt) {
		int de = cnt - c + 1;
		for(int i = 0; de > 0 && i <= len; ++i) {
			if(tmp[i] == 1) {
				tmp[i] = 0;
				--de;
				int p = i + 1;
				while(p <= len && tmp[p] == 1) {
					tmp[p] = 0;
					--de;
				}
				tmp[p] = 1;
			}
			de = -de;
			for(int i = 0; de > 0 && i <= len; ++i) {
				if(tmp[i] == 0) {
					tmp[i] = 1;
					--de;
				}
			}
		}
	}
	LL ret = 0;
	for(int i = len; i >= 0; --i) {

	}
}

void gao(LL x, LL s1, LL s2) {
	if(s1 > s2) swap(s1, s2);
	s1 = max(0LL, s1);
	s2 = min(32LL, s2);

	memset(S, 0, sizeof(S));
	int len = 0;
	int cnt = 0;
	LL tmp_x = x;
	while(tmp_x) {
		if(tmp_x & 1) {
			++cnt;
		}
		S[len++] = tmp_x % 2;
		tmp_x /= 2;
	}

	for(int i = s1; i <= s2; ++i) {
		String tmp = deal(i, len);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		LL x, s1, s2;
		scanf("%I64d%I64d%I64d", &x, &s1, &s2);
		gao(x, s1, s2);
	}
	return 0;
}
