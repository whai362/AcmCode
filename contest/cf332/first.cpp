/*======================================================
# Author: whai
# Last modified: 2015-11-23 20:01
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
	LL a, b, c;
	cin>>a>>b>>c;
	LL ans = a + c + b;
	ans = min(ans, 2 * a + 2 * b);
	ans = min(ans, 2 * a + 2 * c);
	ans = min(ans, 2 * b + 2 * c);
	cout<<ans<<endl;
	return 0;
}

