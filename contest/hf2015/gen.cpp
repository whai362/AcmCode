/*======================================================
# Author: whai
# Last modified: 2015-11-14 16:34
# Filename: gen.cpp
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
	int T = 0;
	for(int n = 1; n <= 100; ++n) {
		for(int m = 1; m <= n + 5; ++m) {
			cout<<n<<' '<<m<<' '<<2<<endl;
			++T;
		}
	}
	cout<<T<<endl;
	return 0;
}

