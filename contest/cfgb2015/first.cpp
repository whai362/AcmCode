/*======================================================
# Author: whai
# Last modified: 2015-12-30 22:54
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

int day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days = 366;
int st = 4;
int main() {
	int x;
	string A, B;
	while(cin>>x>>A>>B) {
		int ans = 0;
		if(B == "week") {
			--x;
			for(int i = st; i < st + 366; ++i) {
				int tmp = i % 7;
				if(tmp == x) {
					++ans;
				}	
			}
		} else {
			for(int i = 0; i < 12; ++i) {
				if(day[i] >= x) {
					++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

