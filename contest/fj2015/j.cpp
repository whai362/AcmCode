/*======================================================
# Author: whai
# Last modified: 2015-12-27 13:14
# Filename: j.cpp
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
	int T;
	cin>>T;
	while(T--) {
		LL n, m;
		cin>>n>>m;
		LL tmp = n - m + 2;
		--tmp;
		//cout<<tmp<<endl;
		if(tmp * 3 >= n) puts("Yes");
		else puts("No");
	}
	return 0;
}

