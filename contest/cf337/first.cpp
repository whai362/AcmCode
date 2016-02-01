/*======================================================
# Author: whai
# Last modified: 2015-12-27 19:05
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

int main() {
	LL n;
	while(cin>>n) {
		if(n % 2) {
			puts("0");
		} else {
			LL half = n / 2;
			cout<<(half - 1)/ 2<<endl;
		}
	}
	return 0;
}

