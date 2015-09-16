#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define PB push_back

#define LL __int64

const int N = 1005;

struct P {
	LL x, y;
	int id;
};

bool cmp1(P a, P b) {
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

bool cmp2(P a, P b) {
	if(a.x == b.x)
		return a.y > b.y;
	return a.x > b.x;
}

vector<P> G[N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		P tmp;
		scanf("%I64d%I64d", &tmp.x, &tmp.y);
		tmp.id = i + 1;
		int bl = tmp.y / N;
		G[bl].PB(tmp);
	}
	for(int i = 0; i < N; ++i) {
		if(i % 2 == 0) sort(G[i].begin(), G[i].end(), cmp1);
		else sort(G[i].begin(), G[i].end(), cmp2);
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < G[i].size(); ++j) {
			cout<<G[i][j].id<<' ';
		}
	}
	cout<<endl;
	return 0;
}
