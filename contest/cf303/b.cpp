/*======================================================
# Author: whai
# Last modified: 2015-10-26 20:09
# Filename: b.cpp
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

const int N = 1e5 + 5;

char S[N], T[N];

int main() {
	scanf("%s", S);
	scanf("%s", T);
	int len = strlen(S);
	int cnt = 0;
	for(int i = 0; i < len; ++i) {
		if(S[i] == T[i]) {
			++cnt;
		}
	}
	if((len - cnt) % 2) {
		puts("impossible");
	} else {
		int nd = (len - cnt) / 2;
		int i = 0;
		for(; i < len && nd > 0; ++i) {
			if(S[i] == T[i]) continue;
			else {
				--nd;
			}
		}
		for(; i < len; ++i) {
			if(S[i] == T[i]) continue;
			else {
				S[i] = T[i];
			}
		}
		cout<<S<<endl;
	}
	return 0;
}

