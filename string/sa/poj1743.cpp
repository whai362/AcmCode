/*poj 1743 Musical Theme
  题意：
  有N个音符的序列来表示一首乐曲，每个音符都是1..88范围内的整数，现在要找一个重复的主题。“主题”是整个音符序列的一个子串，它需要满足如下条件：
  1.长度至少为5个音符。
  2.在乐曲中重复出现。(可能经过转调，“转调”的意思是主题序列中每个音符都被加上或减去了同一个整数值)
  3.重复出现的同一主题不能有公共部分。
  限制：
  1 <= N <= 20000
  思路：
  二分长度用lcp判断是否有重叠部分
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20005;
const int INF = 20000;
int n; //构造后缀数组的字符串的长度
int times; //倍数
int sa[N]; //"排在第几的是谁"
int rank[N], tmp_rank[N]; //"你排第几"
bool cmp_sa(int i, int j) {
	if (rank[i] != rank[j])
		return rank[i] < rank[j];
	else {
		int ri = i + times <= n ? rank[i + times] : -1;
		int rj = j + times <= n ? rank[j + times] : -1;
		return ri < rj;
	}
}
void build_sa(int *S, int *sa) {
	for (int i = 0; i <= n; ++i) {
		sa[i] = i;
		rank[i] = S[i];
	}
	for (times = 1; times <= n; times <<= 1) {
		sort(sa, sa + n + 1, cmp_sa);
		tmp_rank[sa[0]] = 0;
		for (int i = 1; i <= n; ++i) {
			tmp_rank[sa[i]] = tmp_rank[sa[i - 1]] + cmp_sa(sa[i - 1], sa[i]);
		}
		for (int i = 0; i <= n; ++i) {
			rank[i] = tmp_rank[i];
		}
	}
}

int lcp[N];
void build_lcp(int *S, int *sa, int *lcp) {
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

bool ok(int len) {
	int p = 0;
	while(p <= n) {
		while(p <= n && lcp[p] < len) ++p;
		int minn = INF;
		int minp = INF;
		int maxp = 0;
		while(p <= n && lcp[p] >= len) {
			minn = min(minn, lcp[p]);
			maxp = max(maxp, max(sa[p], sa[p+1]));
			minp = min(minp, min(sa[p], sa[p+1]));
			if(maxp - minp > len) return true;
			++p;
		}
	}
	return false;
}

void gao(int *a) {
	build_sa(a, sa);
	build_lcp(a, sa, lcp);
	//for(int i = 0; i <= n; ++i){
	//	cout<<rank[i]<<' ';
	//}
	//cout<<endl;
	int L = 0, R = 20000;
	int mid = (L + R) >> 1;
	while(L + 1 < R){
		if(ok(mid)) L = mid;
		else R = mid;
		mid = (L + R) >> 1;
	}
	++L;
	if(L < 5) puts("0");
	else printf("%d\n", L);
}
int trans(int *a, int *b, int n) {
	int len = 0;
	int minn = 100;
	for(int i = 1; i < n; ++i) {
		b[len] = a[i] - a[i-1];
		minn = min(b[len], minn);
		++len;
	}
	b[len] = minn - 1;
	return len;
}
int a[N], b[N];
int main() {
	while(scanf("%d", &n) && n) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		n = trans(a, b, n);
		gao(b);
	}
	return 0;
}

