/*======================================================
# Author: whai
# Last modified: 2015-10-20 17:24
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

char A[N], B[N], C[N];

int cnt_A[30], cnt_B[30], cnt_C[30];

int main() {
	
	scanf("%s", A);
	scanf("%s", B);
	scanf("%s", C);

	int len_A = strlen(A);
	for(int i = 0; i < len_A; ++i) {
		++cnt_A[A[i] - 'a'];
	}
	int len_B = strlen(B);
	for(int i = 0; i < len_B; ++i) {
		++cnt_B[B[i] - 'a'];
	}
	int len_C = strlen(C);
	for(int i = 0; i < len_C; ++i) {
		++cnt_C[C[i] - 'a'];
	}

	int x = 0, y;
	int maxx = -1, max_x, max_y;
	while(1) {
		int flag = 1;
		for(int i = 0; i < 30; ++i) {
			if(cnt_A[i] < cnt_B[i] * x) {
				flag = 0;
				break;
			}
		}
		if(flag == 0) break;
		for(int i = 0; i < 30; ++i) {
			cnt_A[i] -= cnt_B[i] * x;
		}
		y = N;
		for(int i = 0; i < 30; ++i) {
			if(cnt_C[i] == 0) continue;
			y = min(y, cnt_A[i] / cnt_C[i]);
		}
		if(x + y > maxx) {
			maxx = x + y;
			max_x = x;
			max_y = y;
		}
		for(int i = 0; i < 30; ++i) {
			cnt_A[i] += cnt_B[i] * x;
		}
		++x;
	}
	string ans = "";
	for(int i = 0; i < 30; ++i) {
		cnt_A[i] -= max_x * cnt_B[i] + max_y * cnt_C[i];
	}
	for(int i = 0; i < max_x; ++i) {
		ans += string(B);
	}
	for(int i = 0; i < max_y; ++i) {
		ans += string(C);
	}
	for(int i = 0; i < 30; ++i) {
		for(int j =0; j < cnt_A[i]; ++j) {
			ans += char(i + 'a');
		}
	}
	cout<<ans<<endl;

	return 0;
}

