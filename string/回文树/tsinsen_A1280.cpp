/*======================================================
# Author: whai
#
# Last modified: 2015-10-05 15:37
#
# Filename: tsinsen_A1280.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;
const int M = 26;

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
		S[n] = -1;
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
		return len[last];
	}

	void count() {
		for(int i = p - 1; i >= 0; --i)
			cnt[fail[i]] += cnt[i];
	}
};

PalTree pt;
int len[N];
char str[N];

void gao(char str[]) {
	int ans = 0;
	int n = strlen(str);
	pt.init();

	for(int i = n - 1; i >= 0; --i) {
		len[i] = pt.add(str[i]);
	}
	pt.init();
	for(int i = 0; i < n - 1; ++i) {
		ans = max(ans, pt.add(str[i]) + len[i + 1]);
	}
	printf("%d\n", ans);
}

int main() {
	while(scanf("%s", str) != EOF) {
		gao(str);
	}
	return 0;
}

