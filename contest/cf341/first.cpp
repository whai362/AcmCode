/*======================================================
# Author: whai
# Last modified: 2016-01-31 21:59
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

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {

		LL sum = 0;
		LL minn = 0;
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			if(x & 1) {
				if(minn == 0) minn = x;
				else minn = min(minn, (LL)x);
			}
			sum += x;
		}
		if(sum & 1) {
			cout<<sum - minn<<endl;
		} else {
			cout<<sum<<endl;
		}
	}
	return 0;
}

