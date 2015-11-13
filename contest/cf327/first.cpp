/*======================================================
# Author: whai
# Last modified: 2015-10-25 16:58
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
	double l, p, q;
	cin>>l>>p>>q;
	double t1 = l / (p + q);
	cout<<t1*p<<endl;
	return 0;
}

