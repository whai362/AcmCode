/*======================================================
# Author: whai
#
# Last modified: 2015-10-06 15:18
#
# Filename: tmp.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
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
	double A = 17 * sqrt(2) / 8 + 3;
	double B = 3 - 17 * sqrt(2) / 8;
	double C = 3 + 2 * sqrt(2);
	double D = 3 - 2 * sqrt(2);
	
	int n;
	cin>>n;
	double ans = A * pow(C, n - 1) + B * pow(D, n - 1);
	cout<<ans<<endl;
	return 0;
}
