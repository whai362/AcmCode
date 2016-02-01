/*======================================================
# Author: whai
# Last modified: 2015-12-10 10:49
# Filename: b.cpp
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
#define P pair<LL, LL>
#define X first
#define Y second

const LL INF = 1e16 + 5;

//1
//3
//7
//15
//31
//63

P tab[105];
int tot = 0;
void predo() {
	LL len = 1, sum = 1;
	tab[tot++] = P(len, sum);
	while(len * 2 < INF) {
		sum = sum * 2 + (len + 1);
		len = len * 2 + 1;
		tab[tot++] = P(len, sum);
	}
}

LL gao(LL m) {
	//cout<<m<<endl;
	if(m <= 0) return 0;
	if(m == 1) return tab[0].Y;
	int pos = lower_bound(tab, tab + tot, P(m, INF)) - tab;
	//cout<<tab[pos - 1].X<<' '<<tab[pos - 1].Y<<endl;
	return tab[pos - 1].Y + (m - tab[pos - 1].X) + gao(m - tab[pos - 1].X - 1);
}

int main() {
	predo();
	int T;
	scanf("%d", &T);
	while(T--) {
		LL m;
		scanf("%I64d", &m);
		printf("%I64d\n", gao(m));
	}
	return 0;
}

