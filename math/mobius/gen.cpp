/*======================================================
# Author: whai
# Last modified: 2015-11-03 12:26
# Filename: gen.cpp
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
	int n, q;
	n = 10000, q = 100;
	cout<<n<<' '<<q<<endl;
	for(int i = 0; i < n; ++i) {
		cout<<rand() % 10000<<' ';
	}
	cout<<endl;
	for(int i = 0; i < q; ++i) {
		cout<<rand() % 10000<<endl;
	}
	return 0;
}

