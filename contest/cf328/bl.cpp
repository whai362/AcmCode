/*======================================================
# Author: whai
# Last modified: 2015-11-01 02:15
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

using namespace std;

#define LL unsigned __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const LL INF = 1e18;

int main() {
	LL t, w, b;
	cin>>t>>w>>b;
	if(w < b) swap(w, b);
	LL lcm = (w / __gcd(w, b)) / b;
	LL res = b - 1 + t / lcm * b;
	
	cout<<res<<endl;

	LL d = __gcd(res, t);
	cout<<res/d<<' '<<t/d<<endl;
	return 0;
}

