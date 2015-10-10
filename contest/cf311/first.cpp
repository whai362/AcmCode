/*======================================================
# Author: whai
# Last modified: 2015-10-09 21:59
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

int a[3], b[3];

int main() {
	int n;
	cin>>n;
	for(int i = 0; i < 3; ++i) {
		cin>>a[i]>>b[i];
	}
	int A = min(b[0], n - a[1] - a[2]);
	int B = min(b[1], n - A - a[2]);
	int C = n - A - B;
	cout<<A<<' '<<B<<' '<<C<<endl;
	return 0;
}

