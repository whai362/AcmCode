/*======================================================
# Author: whai
# Last modified: 2015-11-25 00:32
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

const int N = 105;

int main() {
	LL A = 0;
	int n, m;
	int base;
	LL x;
	cin>>n>>base;
	for(int i = 0; i < n; ++i) {
		cin>>x;
		A = A * base + x;
	}
	cin>>m>>base;
	LL B = 0;
	for(int i = 0; i < m; ++i) {
		cin>>x;
		B = B * base + x;
	}
	//cout<<A<<' '<<B<<endl;
	if(A > B) cout<<'>'<<endl;
	else if(A == B) cout<<'='<<endl;
	else cout<<'<'<<endl;
	return 0;
}

