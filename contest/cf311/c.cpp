/*======================================================
# Author: whai
# Last modified: 2015-10-09 22:29
# Filename: c.cpp
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

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int cc[205];

P a[N];

int main() {
	int n;
	scanf("%d", &n);
	
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i].X);
	}
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i].Y);
		sum += a[i].Y;
	}
	
	sort(a, a + n);
	
	int have = 0;

	int ans = INF;
	int cost = 0;
	for(int i = 0; i < n; ++i) {
		int cnt = 0;
		int p = i;
		while(p < n && a[p].X == a[i].X) {
			++cnt;
			++have;
			cost += a[p].Y;
			++p;
		}
		//cout<<cnt<<' '<<p<<endl;
		if(cnt * 2 > have) {
			//cout<<'!'<<sum<<' '<<cost<<endl;
			ans = min(ans, sum - cost);
		} else {
			int need = have - cnt - cnt + 1;
			//cout<<'?'<<cnt<<' '<<half<<' '<<need<<endl;
			int add = 0;
			for(int j = 1; j <= 200; ++j) {
				if(cc[j] == 0) continue;
				if(cc[j] <= need) {
					need -= cc[j];
					add += cc[j] * j;
				} else {
					add += need * j;
					need = 0;
				}
				if(need == 0) break;
			}
			//cout<<sum<<' '<<cost<<' '<<add<<endl;
			ans = min(ans, sum - cost + add);
		}
		for(int j = i; j < p; ++j) {
			++cc[a[j].Y];
		}
		i = p - 1;
	}
	printf("%d\n", ans);
	return 0;
}

