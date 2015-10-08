/*tsinsen A1393. Palisection
  题意：
  给你一个长度n的只由小写字母组成的字符串s。
　我们考虑s的所有连续且回文的子串集合P。位置不同但内容相同的两个串算作不同。
  问从P中选出两个串且他们在s中有公共位置的方法数有几个？
  限制：
  n <= 2 * 1e6
  思路：
  回文树
  首先串S倒着插入构造回文树，处理出以每个下标为结尾的回文串个数，然后处理出后缀和，sum[i]表示开头下标大于等于下标i的回文串个数。
  然后我们再正着插入字符构造回文树，每次插入结束后，ans+=num[i]*sum[i+1]。
  当正着插入结束后，我们求得的ans恰是没有重叠的串的对数，所以我们只要再求得所有的对数，减去ans后就是答案。
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 2 * 1e6 + 5;
const int M = 26;
const int MOD = 51123987;

struct PalTree {
	int nxt[N][M]; //表示编号为i的节点表示的回文串在两边添加字符c以后变成的回文串的编号
	int fail[N]; //表示节点i失配以后跳转不等于自身的节点i表示的回文串的最长后缀回文串
	int cnt[N]; //表示节点i表示的本质不同的串的个数（建树时求出的不是完全的，最后count()函数跑一遍以后才是正确的）
	int num[N]; //表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数
	int len[N]; //表示编号为i的节点表示的回文串的长度（一个节点表示一个回文串）
	int S[N]; //表示第i次添加的字符（一开始设S[0] = -1（可以是任意一个在串S中不会出现的字符））
	int last; //指向新添加一个字母后所形成的最长回文串表示的节点
	int n; //表示添加的字符个数
	int p; //表示添加的节点个数

	int new_node(int x) {
		memset(nxt[p], 0, sizeof(nxt[p]));
		cnt[p] = 0;
		num[p] = 0;
		len[p] = x;
		return p++;
	}

	void init() {
		p = 0;
		new_node(0);
		new_node(-1);
		last = 0;
		n = 0;
		S[0] = -1;
		fail[0] = 1;
	}

	int get_fail(int x) {
		while(S[n - len[x] - 1] != S[n]) x = fail[x];
		return x;
	}

	int add(int x) {
		x -= 'a';
		S[++n] = x;
		int cur = get_fail(last);
		if(!nxt[cur][x]) {
			int now = new_node(len[cur] + 2);
			fail[now] = nxt[get_fail(fail[cur])][x];
			nxt[cur][x] = now;
			num[now] = num[fail[now]] + 1;
		}
		last = nxt[cur][x];
		++cnt[last];
		return num[last];
	}

	void count() {
		for(int i = p - 1; i >= 0; --i)
			cnt[fail[i]] += cnt[i];
	}

	LL pal_str_num() {
		LL ret = 0;
		for(int i = p - 1; i > 0; --i) {
			cnt[fail[i]] = (cnt[fail[i]] + cnt[i]) % MOD;
			ret = (ret + cnt[i]) % MOD;
		}
		return ret;
	}
};

PalTree pt;
char str[N];
int sum[N];

void gao(int n) {
	LL ans = 0;
	pt.init();
	sum[n] = 0;
	for(int i = n - 1; i >= 0; --i) {
		sum[i] = (sum[i + 1] + pt.add(str[i])) % MOD;
	}
	pt.init();
	for(int i = 0; i < n; ++i) {
		ans = (ans + (LL)pt.add(str[i]) * sum[i + 1]) % MOD;
	}
	LL all = pt.pal_str_num();
	ans = (((LL)all * (all - 1) / 2 % MOD - ans) % MOD + MOD) % MOD;
	cout<<ans<<endl;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		scanf("%s", str);
		gao(n);
	}
	return 0;
}

