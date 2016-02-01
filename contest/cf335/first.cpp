/*======================================================
# Author: whai
# Last modified: 2015-12-10 00:02
# Filename: first.cpp
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

const int N = 1e5 + 5;

int a[N];
int pos[N];

int main() {
	int n;
	while(cin>>n) {
		for(int i = 1; i <= n; ++i) {
			cin>>a[i];
			pos[a[i]] = i;
		}
		int ans = 1;
		int tmp = 1;
		for(int i = 2; i <= n; ++i) {
			if(pos[i - 1] < pos[i]) {
				++tmp;
			} else {
				tmp = 1;
			}
			ans = max(ans, tmp);
		}
		cout<<n - ans<<endl;
	}
	return 0;
}

