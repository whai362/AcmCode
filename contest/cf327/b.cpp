/*======================================================
# Author: whai
# Last modified: 2015-10-25 17:13
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

const int N = 105;
const int M = 2 * 1e5 + 5;
char tab[N];
char fan[N];
char str[M];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	for(char i = 'a'; i <= 'z'; ++i) {
		tab[i] = i;
		fan[i] = i;
	}
	for(int i = 0; i < m; ++i) {
		char A[2], B[2];
		scanf("%s%s", A, B);
		swap(tab[fan[A[0]]], tab[fan[B[0]]]);
		swap(fan[A[0]], fan[B[0]]);
	}
	for(int i = 0; i < n; ++i) {
		str[i] = tab[str[i]];
	}
	printf("%s\n", str);
	return 0;
}

