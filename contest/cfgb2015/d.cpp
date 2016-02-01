/*======================================================
# Author: whai
# Last modified: 2015-12-31 00:01
# Filename: d.cpp
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

const int N = 5005;
const int MOD = 1000000007;
char str[N];

LL dp[N][N];

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
void build_sa(char *S, int *sa) {
	n = strlen(S);
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

/*高度数组(lcp)：
  lcp[i] = longest common prefix(sa[i], sa[i+1])
  lcp的一个结论：
  若lcp[rank[i]] = h, 则lcp[rank[i + 1]] >= h - 1

  注意：
  这里要区分清楚lcp的下标其实是相对排名的顺序而言的，和sa的下标代表的意义一样，这点必须记清楚。
 */

int lcp[N];
void build_lcp(char *S, int *sa, int *lcp) {
	int h = 0;
	for (int i = 0; i < n; ++i) {
		int j = sa[rank[i] - 1];
		if (h > 0) --h;
		for (; j + h < n && i + h < n; ++h) {
			if (S[j + h] != S[i + h]) break;
		}
		lcp[rank[i] - 1] = h;
	}
}

int DP[N][18];
void makermq(int n, int b[]) {
    for (int i = 0; i < n; i++)
        DP[i][0] = b[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            DP[i][j] = min(DP[i][j - 1], DP[i + (1 << (j - 1))][j - 1]);
}
int rmq(int s, int v) {
    int k = (int)(log((v - s + 1) * 1.0) / log(2.0));
    return min(DP[s][k], DP[v - (1 << k) + 1][k]);
}

bool gr(int L, int R) {
	int r = L - 1;
	int l = r - (R - L);
	if(l < 0) return true;
	//for(int i = l; i <= r; ++i) {
	//	if(str[i] > str[i - l + L]) return false;
	//	else if(str[i] < str[i - l + L]) return true;
	//}
	//return false;
	int rk1 = rank[l - 1];
	int rk2 = rank[L - 1];

	if(rk1 > rk2) swap(rk1, rk2);
	int comm = rmq(rk1, rk2 - 1);
	//cout<<l<<' '<<r<<' '<<L<<' '<<R<<' '<<' '<<rk1<<' '<<rk2<<' '<<comm<<endl;
	if(comm >= R - L + 1) return false;
	return str[l + comm] < str[L + comm];
}

void gao(int n) {
	dp[1][1] = 1;
	for(int i = 2; i <= n; ++i) {
		dp[i][i] = 1;
		for(int j = 1; j < i; ++j) {
			if(str[i - j + 1] == '0') continue;
			if(!gr(i - j + 1, i)) dp[i][j] = (dp[i][j] + dp[i - j][min(i - j, j - 1)]) % MOD;
			else dp[i][j] = (dp[i][j] + dp[i - j][min(i - j, j)]) % MOD;
		}
		for(int j = 1; j <= i; ++j) {
			dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
		}
	}
	
	cout<<dp[n][n]<<endl;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		scanf("%s", str + 1);
		build_sa(str + 1, sa);
		build_lcp(str + 1, sa, lcp);
		//for(int i = 0; i <= n; ++i) {
		//	cout<<rank[i]<<' ';
		//}
		//cout<<endl;
		//for(int i = 0; i <= n; ++i) {
		//	cout<<lcp[i]<<' ';
		//}
		//cout<<endl;
		makermq(n + 1, lcp);
		gao(n);
	}
	return 0;
}

