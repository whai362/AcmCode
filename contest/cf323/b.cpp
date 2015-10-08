/*===================================================================
# Author: whai
#
# Last modified: 2015-10-04 01:02
#
# Filename: b.cpp
===================================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e3 + 5;

int a[N];
bool used[N];

int main() {
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	int hav = 0;
	int ans = -1;
	while(hav < n) {
		++ans;
		for(int i = 0; i < n; ++i) {
			if(hav >= a[i] && used[i] == 0) {
				++hav;
				used[i] = 1;
			}
		}
		if(hav >= n) break;
		++ans;
		for(int i = n - 1; i >= 0; --i) {
			if(hav >= a[i] && used[i] == 0) {
				++hav;
				used[i] = 1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

