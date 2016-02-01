/*======================================================
# Author: whai
# Last modified: 2015-12-02 01:06
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
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

int main() {
	int p, k;
	cin>>p>>k;
	
	for(int i = 0; i < p; ++i) {
		cout<<k * i % p << "<-" << i<<endl;
	}

	return 0;
}

