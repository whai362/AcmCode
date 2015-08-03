//注意：S下标从0开始, S[n]必须是所有字符中最小的
const int N = 20005;
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
