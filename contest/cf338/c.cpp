/*======================================================
# Author: whai
# Last modified: 2016-01-08 23:01
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
#define ULL unsigned __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second
#define MP make_pair

const LL MOD = 123756789876543217LL;

const int N = 3000;

char A[N], B[N];

map< LL, P > used;

P ans[N];

int main() {
	cin>>A>>B;
	int len_a = strlen(A);
	for(int i = 0; i < len_a; ++i) {
		ULL tmp = 0;
		for(int j = i; j < len_a; ++j) {
			tmp = (tmp * 27 % MOD + A[j] - 'a' + 1) % MOD;
			used[tmp] = P(i + 1, j + 1);
			//cout<<tmp<<' '<<i + 1<<' '<<j + 1<<endl;
		}
	}
	for(int i = len_a - 1; i >= 0; --i) {
		ULL tmp = 0;
		for(int j = i; j >= 0; --j) {
			tmp = (tmp * 27 % MOD + A[j] - 'a' + 1) % MOD;
			used[tmp] = P(i + 1, j + 1);
			//cout<<tmp<<' '<<i + 1<<' '<<j + 1<<endl;
		}
	}
	//cout<<'!'<<endl;
	int len_b = strlen(B);
	int tot = 0;
	for(int i = 0; i < len_b; ++i) {
		ULL tmp = 0;
		int j;
		int flag = 0;
		P sb;
		for(j = i; j < len_b; ++j) {
			tmp = (tmp * 27 % MOD + B[j] - 'a' + 1) % MOD;
			if(used.find(tmp) != used.end()) {
				sb = used[tmp];
			} else {
				break;
			}
		}
		if(i == j) {
			tot = 0;
			break;
		}
		ans[tot++] = sb;
		i = j - 1;
	}
	if(tot != 0) {
		cout<<tot<<endl;
		for(int i = 0; i < tot; ++i) {
			cout<<ans[i].X<<' '<<ans[i].Y<<endl;
		}
	} else {
		cout<<-1<<endl;
	}
	return 0;
}

