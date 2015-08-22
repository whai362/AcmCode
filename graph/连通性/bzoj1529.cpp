#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

const int N = 1e6 + 5;

#define PB push_back

vector<int> G[N];
stack<int> tarjan_stack;
int DFN[N], LOW[N];
int tarjan_set[N];
bool in_stack[N];
int scc_cnt, tarjan_cnt;

void tarjan(int u) {
	DFN[u] = LOW[u] = ++tarjan_cnt;
	tarjan_stack.push(u);
	in_stack[u] = true;

	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(!DFN[v]) {
			tarjan(v);
			LOW[u] = min(LOW[u], LOW[v]);
		} else if(in_stack[v]) {
			LOW[u] = min(LOW[u], DFN[v]);
		}
	}
	
	if(DFN[u] == LOW[u]) {
		int tmp;
		++scc_cnt;
		do{
			tmp = tarjan_stack.top(); tarjan_stack.pop();
			in_stack[tmp] = false;
			tarjan_set[tmp] = scc_cnt;
		} while(tmp != u);
	}
}

void add_edge(int u, int v) {
	G[u].PB(v);
}


int du[N];

void init_tj(int n) {
	scc_cnt = tarjan_cnt = 0;
	memset(DFN, 0, sizeof(DFN));
	memset(LOW, 0, sizeof(LOW));
	memset(in_stack, 0, sizeof(in_stack));
	memset(tarjan_set, 0, sizeof(tarjan_set));
	memset(du, 0, sizeof(du));
	for(int i = 0; i <= n; ++i) G[i].clear();
}


void gao(int n) {
	for(int i = 0; i < n; ++i) {
		if(!DFN[i]) tarjan(i);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < G[i].size(); ++j) {
			int u = tarjan_set[i];
			int v = tarjan_set[G[i][j]];
			if(u == v) continue;
			++du[v];
		}
	}
	int ans = 0;
	for(int i = 0; i < scc_cnt; ++i) {
		if(du[i] == 0) ++ans;
	}
	cout<<ans<<endl;
}

int main() {
	int n;
	scanf("%d", &n);
	init_tj(n);
	for(int i = 0; i < n; ++i) {
		int u, v;
		v = i;
		scanf("%d", &u); --u;
		add_edge(u, v);
	}
	gao(n);
}
