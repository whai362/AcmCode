/*======================================================
# Author: whai
# Last modified: 2015-10-28 11:55
# Filename: h.cpp
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
	LL n, m;
	cin>>n>>m;

	if(n > m) swap(n, m);
	cout<<n * (m + 1)<<endl;

	return 0;
}
