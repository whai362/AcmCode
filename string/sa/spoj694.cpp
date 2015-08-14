/*spoj 694 Distinct Substrings4
  题意：
  给出S, 求不重复子串的个数
  限制：
  |S| <= 1000
  思路：
  利用lcp进行统计
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1005;

int n;
int times;
int sa[N];
int rank[N], tmp_rank[N];

bool cmp_sa(int i, int j) {
	if(rank[i] != rank[j])
		return rank[i] < rank[j];
	else {
		int ri = i + times <= n ? rank[i + times] : -1;
		int rj = j + times <= n ? rank[j + times] : -1;
		return ri < rj;
	}
}

void build_sa(char *S, int *sa) {
	n = strlen(S);
	for(int i = 0; i <= n; ++i) {
		sa[i] = i;
		rank[i] = S[i];
	}

	for(times = 1; times <= n; times <<= 1) {
		sort(sa, sa + n + 1, cmp_sa);
		tmp_rank[sa[0]] = 0;
		for(int i = 1; i <= n; ++i) {
			tmp_rank[sa[i]] = tmp_rank[sa[i - 1]] + cmp_sa(sa[i - 1], sa[i]);
		}
		for(int i = 0; i <= n; ++i) {
			rank[i] = tmp_rank[i];
		}
	}
}

int lcp[N];
void build_lcp(char *S, int *sa, int *lcp) {
	int h = 0;
	for(int i = 0; i < n; ++i) {
		int j = sa[rank[i] - 1];
		if(h > 0) --h;
		for(; j + h < n && i + h < n; ++h) {
			if(S[j + h] != S[i + h]) break;
		}
		lcp[rank[i] - 1] = h;
	}
}

char str[N];

void gao() {
	build_sa(str, sa);
	build_lcp(str, sa, lcp);
	int ans = 0;
	for(int i = 0; i <= n; ++i) {
		ans += n - sa[i];
		if(i) ans -= lcp[i - 1];
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", str);
		gao();
	}
	return 0;
}
