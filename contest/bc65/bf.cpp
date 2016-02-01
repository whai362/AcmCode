/*======================================================
# Author: whai
# Last modified: 2015-12-07 11:46
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
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

int a[15];

void out(string str) {
	for(int i = 0; i < str.length(); ++i) {
		int cnt = 0;
		for(int j = 0; j < i; ++j) {
			for(int k = j + 1; k <= i; ++k) {
				if(str[j] > str[k]) {
					++cnt;
				}
			}
		}
		a[i] = cnt;
	}
	cout<<str<<' ';
	for(int i = 0; i < str.length(); ++i) {
		cout<<a[i]<<' ';
	}
	cout<<endl;
}

void bf() {
	int n;
	cin>>n;
	string str = "";
	for(int i = 1; i <= n; ++i) {
		str += i + '0';
	}
	out(str);
	while(next_permutation(str.begin(), str.end())) {
		out(str);
	}
}

int main() {
	bf();
	return 0;
}

