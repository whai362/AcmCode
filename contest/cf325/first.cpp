/*======================================================
# Author: whai
# Last modified: 2015-10-12 16:53
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N =  105;

int a[N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		int tmp = 0;
		if(a[i] == 0) {
			int p = i;
			while(p < n && a[p] == 0) {
				++p;
				++tmp;
			}
			if(i == 0 || p == n) {
				cnt += tmp;
			} else {
				if(tmp > 1) {
					cnt += tmp;
				}
			}
			i = p - 1;
		}
	}
	cout<<n - cnt<<endl;
	return 0;
}

