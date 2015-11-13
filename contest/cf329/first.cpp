/*======================================================
# Author: whai
# Last modified: 2015-11-05 00:44
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

string str[105];

bool ok(int id, char a, char b) {
	for(int i = 0; i < str[id].length(); ++i) {
		if(str[id][i] != a && str[id][i] != b) return false;
	}
	return true;
}

int main() {
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i) {
		cin>>str[i];
	}
	int ans = 0;
	for(char a = 'a'; a <= 'z'; ++a) {
		for(char b = a + 1; b <= 'z'; ++b) {
			int tmp = 0;
			for(int i = 0; i < n; ++i) {
				if(ok(i, a, b)) {
					tmp += str[i].length();
				}
			}
			ans = max(ans, tmp);
		}
	}
	cout<<ans<<endl;
	return 0;
}

