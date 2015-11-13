/*======================================================
# Author: whai
# Last modified:	2015-10-28 12:46
# Filename:		i.cpp
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
	double r, R, h;
	cin>>r>>R>>h;
	double tmp = (R - r);
	tmp = h / tmp;
	tmp = atan(tmp);
	tmp /= 2;
	tmp = R * tan(tmp);
	tmp = min(h / 2, tmp);
	printf("%.10f\n", tmp);
	return 0;
}
