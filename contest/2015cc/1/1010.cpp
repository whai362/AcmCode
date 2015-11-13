/*======================================================
# Author: whai
# Last modified: 2015-11-01 13:10
# Filename: 1010.cpp
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e6 + 5;

const int MAXB = 2;
int Ntot = 0;

struct Node {
	int br[MAXB];
	int num;
	LL x;
	void clear() {
		memset(br, -1, sizeof(br));
		num = 0;
		x = 0;
	}
} node[N * 35];

void insert(LL x) {
	int cur = 0;
	for(int i = 32; i >= 0; --i) {
		bool id = ((1LL << i) & x) > 0 ? 1 : 0;
		if(node[cur].br[id] == -1) {
			node[Ntot].clear();
			node[cur].br[id] = Ntot;
			++Ntot;
		}
		++node[cur].num;
		cur = node[cur].br[id];
	}
	++node[cur].num;
	node[cur].x = x;
}

void del(LL x) {
	int cur = 0;
	for(int i = 32; i >= 0; --i) {
		--node[cur].num;
		bool id = ((1LL << i) & x) > 0 ? 1 : 0;
		cur = node[cur].br[id];
	}
	--node[cur].num;
	if(node[cur].num == 0) node[cur].x = 0;
}

LL find(LL x) {
	int cur = 0;
	for(int i = 32; i >= 0; --i) {
		bool id = ((1LL << i) & x) > 0 ? 1 : 0;
		//if(x == 9) cout<<id<<endl;
		if(node[cur].br[!id] != -1 && node[node[cur].br[!id]].num > 0) {
			//if(x == 9) cout<<i<<endl;
			cur = node[cur].br[!id];
		} else if(node[cur].br[id] != -1 && node[node[cur].br[id]].num > 0) {
			cur = node[cur].br[id];
		} else {
			break;
		}
	}
	//cout<<x<<' '<<node[cur].x<<endl;
	return x ^ node[cur].x;
}



LL a[1005];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		Ntot = 0;
		node[Ntot++].clear();
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%I64d", &a[i]);
		}
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				LL tmp = a[i] + a[j];
				insert(tmp);
			}
		}
		LL ans = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == j) continue;
				LL tmp = a[i] + a[j];
				del(tmp);
			}
			ans = max(ans, find(a[i]));
			for(int j = 0; j < n; ++j) {
				if(i == j) continue;
				LL tmp = a[i] + a[j];
				insert(tmp);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

