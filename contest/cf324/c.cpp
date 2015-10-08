/*======================================================
# Author: whai
# Last modified: 2015-10-07 01:03
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

string a, b, c;

bool vis[N];
char ans[N];
int main() {
	int n, t;
	cin>>n>>t;
	cin>>a>>b;

	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] == b[i]) {
			++cnt;
			vis[i] = 1;
		}
	}
	int leave = n - cnt;
	int minn = n - (leave / 2 + cnt);
	if(t < minn) {
		puts("-1");
	} else {
		if(leave <= t) {
			int nd = t - leave;
			for(int i = 0; i < n; ++i) {
				if(nd == 0 && vis[i] == 1) ans[i] = a[i];
				else if(vis[i] == 1) {
					--nd;
					ans[i] = (a[i] - 'a' + 1) % 26 + 'a';
				} else {
					for(char ch = 'a'; ch <= 'z'; ++ch) {
						if(ch != a[i] && ch != b[i]) {
							ans[i] = ch;
							break;
						}
					}
				}
			}
		} else {
			for(int i = 0; i < n; ++i) {
				if(vis[i]) ans[i] = a[i];
			}
			int c1, c2;
			c1 = c2 = leave - t;
			for(int i = 0; i < n; ++i) {
				if(vis[i] == 1) continue;
				ans[i] = a[i];
				--c1;
				vis[i] = 1;
				if(c1 == 0) break;
			}

			for(int i = n - 1; i >= 0; --i) {
				if(vis[i] == 1) continue;
				ans[i] = b[i];
				--c2;
				vis[i] = 1;
				if(c2 == 0) break;
			}
			for(int i = 0; i < n; ++i) {
				if(vis[i] == 1) continue;
				for(char ch = 'a'; ch <= 'z'; ++ch) {
					if(ch != a[i] && ch != b[i]) {
						ans[i] = ch;
						break;
					}
				}
			}
		}
		puts(ans);
	}
	
	return 0;
}

