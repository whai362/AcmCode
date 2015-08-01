#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 600005;

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
void build_sa(string str, int *sa) {
	n = str.length();
	for (int i = 0; i <= n; ++i) {
		sa[i] = i;
		rank[i] = i < n ? str[i] : -1;
	}
	for (times = 1; times <= n; times <<= 1) {
		sort(sa, sa + n + 1, cmp_sa);
		tmp_rank[sa[0]] = 0;
		for (int i = 1; i <= n; ++i) {
			tmp_rank[sa[i]] = tmp_rank[sa[i - 1]] + (cmp_sa(sa[i - 1], sa[i]) ? 1 : 0);
		}
		for (int i = 0; i <= n; ++i) {
			rank[i] = tmp_rank[i];
		}
	}
}

bool contain(string S, string T, int *sa) {
	int L = 0, R = S.length();
	while(L + 1 < R) {
		int mid = (L + R) >> 1;
		if(S.compare(sa[mid], T.length(), T) < 0) L = mid;
		else R = mid;
	}
	cout<<R<<endl;
	return S.compare(sa[R], T.length(), T) == 0;
}

int lcp[N];
void build_lcp(string S, int *sa, int *lcp) {
	int n = S.length();
	for(int i = 0; i <= n; ++i)
		rank[sa[i]] = i;
	int h = 0;
	lcp[0] = 0;
	for(int i = 0; i < n; ++i) {
		int j = sa[rank[i] - 1];
		if(h > 0) --h;
		for(; j + h < n && i + h < n; ++h) {
			if(S[j + h] != S[i + h]) break;
		}
		lcp[rank[i] - 1] = h;
	}
}	

void gao(string S, string T){
	int len = S.length();
	S += '#' + T;
	build_sa(S, sa);
	build_lcp(S, sa, lcp);
	//for(int i = 0; i <= S.length(); ++i)
	//	cout<<sa[i]<<' ';
	//cout<<endl;
	//for(int i = 0; i <= S.length(); ++i)
	//	cout<<lcp[i]<<' ';

	int ans = 0;
	for(int i = 0; i < S.length(); ++i){
		if((sa[i] < len) != (sa[i + 1] < len))
			ans = max(ans, lcp[i]);
	}
	printf("Nejdelsi spolecny retezec ma delku %d.\n", ans);
}

int main() {
	int TT;
	cin>>TT;
	getchar();
	while(TT--){
		string S, T;
		getline(cin,S);
		getline(cin,T);
		gao(S, T);
	}
	return 0;
}
