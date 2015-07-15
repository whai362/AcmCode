#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define sz(x) (int)(x.size())
#define LL long long

vector<int> eight;

vector<int> four;

int oppose[1 << 16] = {};

int v[16], Cas = 1;

vector<int> fournum[1 << 16];

int Hash[20000] = {};

void init() {
	for (int i = 0; i < (1 << 16); i ++) {
		int cnt = 0, opp = 0;
		for (int j = 0; j < 16; j ++) {
			if (i & (1 << j)) {
				cnt ++;
			} else {
				opp = opp + (1 << j);
			}
		}
		oppose[i] = opp;
		if (cnt == 8) {
			eight.push_back(i);
		}
		if (cnt == 4) {
			four.push_back(i);
			for (int j = 0; j < 16; j ++) {
				if (i & (1 << j)) {
					fournum[i].push_back(j);
				}
			}
		}
	}
}

vector<int> num[1 << 16];

int calc(int a, int b, int c, int d) {
	return a + b * 2 + c * 3 + d * 4;
}

int ans[1 << 16];

void work() {
	printf("Case %d: ", Cas ++);
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < (1 << 16); i ++) {
		num[i].clear();
	}
	for (int i = 1; i <= 15; i ++) {
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < sz(four); i ++) {
		int value = four[i];
		for (int i1 = 0; i1 < 4; i1 ++) {
			for (int i2 = 0; i2 < 4; i2 ++) {
				if (i1 == i2) continue;
				for (int i3 = 0; i3 < 4; i3 ++) {
					if (i3 == i1 || i3 == i2) continue;
					for (int i4 = 0; i4 < 4; i4 ++) {
						if (i4 == i1 || i4 == i2 || i4 == i3) continue;
						int key = calc(v[fournum[value][i1]], v[fournum[value][i2]], v[fournum[value][i3]], v[fournum[value][i4]]);
						num[value].push_back(key);
					}
				}
			}
		}
	}
	for (int i = 0; i < sz(four); i ++) {
		for (int j = 0; j < sz(four); j ++) {
			int a = four[i], b = four[j];
			if (a & b) continue;
			int c = a | b;
			for (int k = 0; k < sz(num[a]); k ++) {
				Hash[num[a][k]] ++;
			}
			for (int k = 0; k < sz(num[b]); k ++) {
				ans[c] += Hash[num[b][k]];
			}
			for (int k = 0; k < sz(num[a]); k ++) {
				Hash[num[a][k]] --;
			}
		}
	}
	LL res = 0ll;
	for (int i = 0; i < sz(eight); i ++) {
		int a = eight[i], b = oppose[a];
		res = res + 1ll * ans[a] * ans[b];
	}
	cout << res/8 << endl;
}

int main() {
	init();
	while (scanf("%d", &v[0]) != EOF) {
		if (v[0] == 0) {
			break;
		}
		work();
	}
	return 0;
}
