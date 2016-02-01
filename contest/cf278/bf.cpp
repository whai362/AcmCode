/*======================================================
# Author: whai
# Last modified: 2015-12-05 16:08
# Filename: bf.cpp
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

int a[15];

bool ok(int n) {
	bool vis[15] = {0};
	int tmp = 1;
	for(int i = 0; i < n; ++i) {
		tmp = (tmp * a[i]) % n;
		if(vis[tmp]) return false;
		vis[tmp] = 1;
	}
	return true;
}

int ans[15];

int main() {
	int n;
	while(cin>>n) {
		for(int i = 0; i < n; ++i) {
			a[i] = i + 1;
		}
		int flag = 0;
		if(!ok(n))
			while(next_permutation(a, a + n)) {
				if(ok(n)) {
					flag = 1;
					for(int i = 0; i < n; ++i) {
						cout<<a[i]<<' ';
					}
					cout<<endl;
				}
			}
		else flag = 1;
		//if(flag)
		//for(int i = 0; i < n; ++i) {
		//	cout<<ans[i]<<' ';
		//}
		//cout<<endl;
	}
	return 0;
}

