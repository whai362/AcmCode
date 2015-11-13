/*======================================================
# Author: whai
# Last modified: 2015-11-06 14:32
# Filename: c.cpp
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
const int N = 55;
P a[N];

int main() {
	int n;
	scanf("%d", &n);
	int r;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a[i].X, &a[i].Y, &r);
	}
	string left = "(((1-abs((t-", mid = ")))+abs((abs((t-", right = "))-1)))";
	string ans1 = "";
	string ans2 = "";
	for(int i = 0; i < n - 1; ++i) {
		ans1 += "(";
		ans2 += "(";
	}	
	for(int i = 0; i < n; ++i) {
		string num = to_string(i);
		ans1 += left + num + mid + num + right + "*" + to_string(a[i].X / 2) + ")";
		ans2 += left + num + mid + num + right + "*" + to_string(a[i].Y / 2) + ")";
		if(i != 0) ans1 += ")", ans2 += ")";
		if(i != n - 1) ans1 += "+", ans2 += "+";
	}
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	return 0;
}

