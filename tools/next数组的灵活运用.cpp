/*1. 首先是next数组的常规用法
  返回模式串T在主串中首次出现的位置(从0开始)
  返回模式串T在主串中首次出现的次数
 */
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1000005;
int nxt[N];
char S[N], T[N];
int slen, tlen;
/*这个模板 字符串是从0开始的
  nxt数组是从1开始的
 */
void get_next() {
	int j, k;
	j = 0; k = -1; nxt[0] = -1;
	while (j < tlen)
		if (k == -1 || T[j] == T[k])
			nxt[++j] = ++k;
		else
			k = nxt[k];

}
/*返回模式串T在主串S中首次出现的位置
  返回的位置是从0开始的。
 */
int kmp_index() {
	int i = 0, j = 0;
	while (i < slen && j < tlen) {
		if (j == -1 || S[i] == T[j]) {
			i++; j++;
		}
		else
			j = nxt[j];
	}
	if (j == tlen)
		return i - tlen;
	else
		return -1;
}
//返回模式串在主串S中出现的次数
int kmp_count() {
	int ans = 0;
	int j = 0;
	for (int i = 0; i < slen; i++) {
		while (j > 0 && S[i] != T[j])
			j = nxt[j];
		if (S[i] == T[j])
			j++;
		if (j == tlen) {
			ans++;
			j = nxt[j];
		}
	}
	return ans;
}
int main() {
	int TT;
	cin >> TT;
	while (TT--) {
		cin >> T >> S;
		slen = strlen(S);
		tlen = strlen(T);
		get_next();
		for (int i = 1; i <= tlen; ++i) {
			cout << nxt[i] << ' ';
		}
		cout << endl;
		cout << "模式串T在主串S中首次出现的位置是: " << kmp_index() << endl;
		cout << "模式串T在主串S中出现的次数为: " << kmp_count() << endl;
	}
	return 0;
}
/*1
  abcabcabc abc

  nxt[1~n]为：
  0 0 0 1 2 3 4 5 6
 */


/*2. 对于任意一个字符串，问这个字符串最多由多少个重复的子串构成。
  子串长度=len-next[len]
  如：
  aaaa 子串长度=1
  aaab 子串长度=4
  ababa 子串长度=2
  aabaabaa 子串长度=3
  不一定整除
 */
/*poj 2406
  题意：
  给出一个字符串，问这个字符串最多由多少个重复的子串构成。
  限制：
  1 <= len <= 1e6
 */
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 1000005;
int main() {
	while (scanf("%s", T) != EOF) {
		if (T[0] == '.') break;
		tlen = strlen(T);
		get_next();
		int zq = tlen - nxt[tlen];
		if (tlen % zq == 0)
			printf("%d\n", tlen / zq);
		else
			puts("1");
	}
	return 0;
}

/*3. 给一个任意一个字符串，求相同的前缀和后缀
  如：
  ababab
  相同的前后缀为：
  ab
  abab
  ababab
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1000005;
int ans[N], cnt;
int main() {
	while (scanf("%s", T) != EOF) {
		tlen = strlen(T);
		get_next();
		cnt = 0;
		int i = tlen;
		while (i > 0) {
			ans[cnt++] = i;
			i = nxt[i];
		}
		for (int i = cnt - 1; i >= 0; --i) {
			printf("%d%c", ans[i], i == 0 ? '\n' : ' ');
		}
	}
	return 0;
}
