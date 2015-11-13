/*======================================================
# Author: whai
# Last modified: 2015-11-10 21:03
# Filename: bzoj1257.cpp
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

int main() {
	LL n, k;
	cin>>n>>k;
	LL ls = 0;
	LL ans = 0;
	for(int i = 1; i <= min(n, k); i = ls + 1) {
		ls = min(n, k / (k / i));
		LL s = k % i, t = s - (ls - i) * (k / i);
		cout<<i<<' '<<ls<<' '<<s<<' '<<t<<endl;
		ans += (s + t) * (ls - i + 1) / 2;
	}
	if(n > k) {
		ans += (n - k) * k;
	}
	cout<<ans<<endl;
	return 0;
}

