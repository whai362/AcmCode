#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20005;
const int INF = 20001;
int n; //构造后缀数组的字符串的长度
int times; //倍数
int sa[N]; //"排在第几的是谁"
int rank[N], tmp_rank[N]; //"你排第几"
bool cmp_sa(int i, int j) {
	if (rank[i] != rank[j])
		return rank[i] < rank[j];
	else {
		int ri = i + times <= n ? rank[i + times] : -1;	//可能会有bug
		int rj = j + times <= n ? rank[j + times] : -1;
		return ri < rj;
	}
}
void build_sa(int *S, int *sa) {
	for (int i = 0; i <= n; ++i) {
		sa[i] = i;
		rank[i] = S[i]; //最小值这里常出bug, 最好保证S为正
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

bool used[N];

bool ok(int len, int k){
	bool ret = false;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(lcp[i] >= len){
			if(used[sa[i]] == 0){
				used[sa[i]] = 1;
				++cnt;
			}
			if(used[sa[i+1]] == 0){
				used[sa[i+1]] = 1;
				++cnt;
			}
		}
		else cnt = 0;
		if(cnt >= k) ret = true;
	}
	for(int i = 0; i < n; ++i)
		used[sa[i]] = used[sa[i+1]] = 0;
	return ret;
}

void gao(int *a, int k, int n){
	a[n] = -1;
	build_sa(a, sa);
	build_lcp(a, sa, lcp);
	//for(int i = 0; i <= n; ++i){
	//	cout<<lcp[i]<<' ';
	//}
	//cout<<endl;
	int L = 0, R = INF;
	while(L + 1 < R){
		int mid = (L + R) >> 1;
		if(ok(mid, k)) L = mid;
		else R = mid;
	}
	printf("%d\n", L);
}

int a[N];
int main(){
	int k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	gao(a, k, n);
	return 0;
}
