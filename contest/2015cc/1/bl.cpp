/*======================================================
# Author: whai
# Last modified: 2015-11-01 13:49
# Filename: bl.cpp
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

int a[105];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int ans = 0;
		int n;
		cin>>n;
		for(int i = 0; i < n; ++i) {
			cin>>a[i];
		}
		int A, B, C;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int k = 0; k < n; ++k) {
					if(i == j || i == k || j == k) continue;
					int tmp = a[i] ^ (a[j] + a[k]);
					if(tmp > ans) {
						A = a[i];
						B = a[j] + a[k];
						ans = tmp;
					}
				}
			}
		}
	//	cout<<A<<' '<<B<<endl;
		cout<<ans<<endl;
	}
	return 0;
}

