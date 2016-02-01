/*======================================================
# Author: whai
# Last modified: 2015-12-27 15:29
# Filename: G.cpp
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
#define P pair<int, int>
#define X first
#define Y second

const int N = 2005;

char str[N];

int maxx[1<<17];

void init() {
	memset(maxx, 0, sizeof(maxx));
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		int n, k;
		cin>>n>>k;
		scanf("%s", str);
		int len = strlen(str);
		for(int i = 0; i < len; ++i) {
			int st = 0;
			for(int j = i; j < len; ++j) {
				st |= (1 << (str[j] - 'a'));
				maxx[st] = max(maxx[st], j - i + 1);
			}
		}
		
		
		int LIM = 1 << 16;

		for(int i = 0; i < LIM; ++i) {
			for(int j = 0; j < k; ++j) {
				int tmp = (i | (1 << j));
				maxx[tmp] = max(maxx[tmp], maxx[i]);
			}
		}

		//cout<<'!'<<endl;


		int ans = 0;

		for(int i = 0; i < LIM; ++i) {
			int tmp = 0;
			for(int j = 0; j < k; ++j) {
				if((i & (1 << j)) == 0) {
					tmp |= (1 << j);
				}
			}
			ans = max(ans, maxx[i] * maxx[tmp]);
		}
		
		cout<<ans<<endl;
	}
	return 0;
}

