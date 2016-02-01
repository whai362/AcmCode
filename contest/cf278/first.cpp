/*======================================================
# Author: whai
# Last modified: 2015-12-05 14:30
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

bool ok(LL x) {
	char str[20];
	sprintf(str, "%I64d\n", x);
	int len = strlen(str);
	for(int i = 0; i < len; ++i) {
		if(str[i] == '8') return true;
	}
	return false;
}

int _abs(int x) {
	if(x < 0) return -x;
	return x;
}

void gao(LL x) {
	int ans = 100;
	for(int i = 1; i <= 20; ++i) {
		if(ok(x + i)) {
			ans = min(_abs(i), ans);
		}
	}
	cout<<ans<<endl;
}

int main() {
	LL a;
	while(cin>>a) {
		gao(a);
	}

	return 0;
}

