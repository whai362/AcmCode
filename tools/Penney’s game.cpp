/*题意：
  小A和小B在玩一个游戏，他们一开始每人手上都有一个01字符串，其中记小A手上的为A串，小B手上的为B串。
  现在有一枚均匀的硬币，以及一个空字符串S，游戏开始后每一回合都会投掷这枚硬币，如果正面向上，就在S后面添加一个字符'1'，否则添加一个字符'0'。
  一旦某一回合结束时A串成为了S的子串，小A就赢了，同样如果B串成为了S的子串，小B就赢了，有一个人获得胜利时游戏结束。为了避免两个人同时胜利的情况，保证A不为B的后缀，B也不为A的后缀。
  在已知A和B的情况下，这个游戏是不是公平的呢，公平意味着小A与小B拥有相同的胜率，若不公平谁更有可能赢？
  限制：
  1 <= |A|,|B| <= 100000
  思路：
  1. 首先要知道Penney’s game的结论：
  假如 a 和 b 是两个 n 位 01 串。如果 a 和 b 完全相等，那么记一个数字 1 ，如果不相等，那么记一个数字 0 。接下来，比较 a 的后面 n – 1 位以及 b 的前面 n – 1 位，如果相等，那么接着记一个数字 1 ，如果不相等，那么接着记一个数字 0 。接下来，比较 a 的后 n – 2 位以及 b 的前 n – 2 位，并根据比较结果记下数字 0 或者数字 1 。不断这样做下去，直到最后比较 a 的最后面 1 位和 b 的最前面 1 位，并产生新的数字。在整个过程中，你会依次记下 n 个数字，最终会得到一个 n 位的 01 串。把它当作一个二进制数，并转换成十进制。我们把最终的结果记为 L(a, b) 。举几个例子：
  L(10110, 10110) = (10010)2 = 18
  L(10110, 01011) = (00001)2 = 1
  L(01011, 01011) = (10000)2 = 16
  L(01011, 10110) = (01001)2 = 9
  那么， 01 串 a 和 b 的胜率之比就是
  (L(b, b) – L(b, a)) : (L(a, a) – L(a, b))

  2. 因为数据量比较大，要用kmp来优化。
  kmp优化方式如下：
  先算出模式串的next数组，不断地和母串的最后一位匹配，记录可以匹配的长度即可。

  3. 用java大数会超时，要用c++模拟二进制大数减法。
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int N = 100050;
LL aa[N / 50], bb[N / 50], ab[N / 50], ba[N / 50];
int next[N];
void getNext(char T[], int len) {
	int i, j;
	i = 0;
	j = next[0] = -1;
	while (i < len) {
		if (j == -1 || T[i] == T[j]) next[++i] = ++j;
		else j = next[j];
	}
}
void deal(char S[], char T[], int slen, int tlen, LL res[]) {
	for (int i = 0; i <= max(slen / 50, tlen / 50); ++i) res[i] = 0;
	int i = 0, j = 0;
	if (slen >= tlen) i += slen - tlen;
	else j += tlen - slen;
	getNext(T, tlen);
	while (i < slen) {
		if (j == -1 || S[i] == T[j]) {
			++i; ++j;
			if (i == slen && j != 0) {
				int bl = (j - 1) / 50;
				int mv = (j - 1) % 50;
				res[bl] |= (1LL) << mv;
				--i;
				j = next[j - 1];
			}
		}
		else j = next[j];
	}
}
char A[N], B[N];
void print(LL a[], int len) {
	for (int i = 0; i < len; ++i) {
		int bl = i / 50;
		int mv = i % 50;
		cout << (a[bl] & (1LL << mv)) << ' ';
	}
	cout << endl;
}
void sub(LL a[], LL b[], int alen, int blen) {
	int lim = max(alen / 50, blen / 50);
	int c = 0;
	for (int i = 0; i <= lim; ++i) {
		LL tmp = a[i] - b[i] - c;
		if (tmp < 0) { c = 1, tmp += (1LL) << 50; }
		else c = 0;
		a[i] = tmp;
	}
}
int n, m;
int cmp(LL a[], LL b[], int alen, int blen) {
	int lim = max(alen / 50, blen / 50);
	int ret = 0;
	for (int i = lim; i >= 0; --i) {
		if (a[i] > b[i]) { ret = 1; break; }
		if (a[i] < b[i]) { ret = -1; break; }
	}
	return ret;
}
void gao() {
	int fa, fb;
	sub(bb, ba, m, m);
	sub(aa, ab, n, n);
	int ans = cmp(bb, aa, m, n);
	if (ans == 0) puts("Equal");
	else if (ans == 1) puts("Hamlet");
	else puts("Laertes");
}
int main() {
	while (scanf("%d%d", &n, &m) && (n || m)) {
		scanf("%s%s", A, B);
		deal(A, A, n, n, aa);
		deal(B, B, m, m, bb);
		deal(A, B, n, m, ab);
		deal(B, A, m, n, ba);
		//print(aa,n);
		//print(ab,n);
		//print(bb,m);
		//print(ba,m);
		gao();
	}
	return 0;
}
