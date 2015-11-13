/*======================================================
# Author: whai
# Last modified: 2015-10-23 14:27
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

int main() {
	LL k, n, w;
	cin>>k>>n>>w;
	LL ans = (1 + w) * w / 2 * k - n;
	if(ans <= 0) cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}

