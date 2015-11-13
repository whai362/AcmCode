/*======================================================
# Author: whai
# Last modified: 2015-10-27 14:58
# Filename: poj1236.cpp
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
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int MAX_V = 105;

vector<int> G[MAX_V];
stack<int> tarjan_stack;
int DFN[MAX_V], LOW[MAX_V];
int tarjan_set[MAX_V];
bool in_stack[MAX_V];
int scc_cnt, tarjan_cnt;
void tarjan(int u) {
	DFN[u] = LOW[u] = ++tarjan_cnt;
	tarjan_stack.push(u);
	in_stack[u] = true;

	for (int i = 0; i < G[u].size(); ++i) {
		int ch = G[u][i];
		if (!DFN[ch]) {
			tarjan(ch);
			LOW[u] = min(LOW[u], LOW[ch]);
		} else if (in_stack[ch]) {
			LOW[u] = min(LOW[u], DFN[ch]);
		}
	}

	if (DFN[u] == LOW[u]) {
		int tmp;
		++scc_cnt;
		do {
			tmp = tarjan_stack.top(); tarjan_stack.pop();
			in_stack[tmp] = false;
			tarjan_set[tmp] = scc_cnt;
		}
		while (tmp != u);
	}
}
void add_edge(int u, int v) {
	G[u].PB(v);
}
void init_tarjan(int n) {
	scc_cnt = tarjan_cnt = 0;
	memset(DFN, 0, sizeof(DFN));
	memset(LOW, 0, sizeof(LOW));
	memset(in_stack, 0, sizeof(in_stack));
	memset(tarjan_set, 0, sizeof(tarjan_set));
	for (int i = 0; i <= n; ++i)
		G[i].clear();
}
//点的序号从0开始

int in_deg[MAX_V];
int out_deg[MAX_V];

void gao(int n) {
	for(int i = 0; i < n; ++i) {
		if (!DFN[i]) tarjan(i);
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < G[i].size(); ++j) {
			int u = tarjan_set[i];
			int v = tarjan_set[G[i][j]];
			if(u == v) continue;
			++out_deg[u];
			++in_deg[v];
		}
	}

	int ans1 = 0;
	int ans2 = 0;
	for(int i = 1; i <= scc_cnt; ++i) {
		if(in_deg[i] == 0) ++ans1;
		if(out_deg[i] == 0) ++ans2;
	}
	cout<<ans1<<endl;
	if(scc_cnt == 1) cout<<'0'<<endl;
	else cout<<max(ans1, ans2)<<endl;
}

void init(int n) {
	init_tarjan(n);
}

int main() {
	int n;
	scanf("%d", &n);
	init(n);

	for(int i = 0; i < n; ++i) {
		int u = i;
		int v;
		while(scanf("%d", &v) && v) {
			--v;
			add_edge(u, v);
		}
	}

	gao(n);

	return 0;
}

