/*======================================================
# Author: whai
# Last modified: 2015-12-10 14:42
# Filename: a1.cpp
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

int a[2][3];

int main() {
	for(int i = 0; i < 2; ++i) {
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	int nd = 0, lv = 0;
	for(int i = 0; i < 3; ++i) {
		if(a[0][i] > a[1][i]) {
			int tmp = a[0][i] - a[1][i];
			lv += tmp / 2;
		} else if(a[0][i] < a[1][i]) {
			int tmp = a[1][i] - a[0][i];
			nd += tmp;
		}
	}
	//cout<<nd<<' '<<lv<<endl;
	if(nd <= lv) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

