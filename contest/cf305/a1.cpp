/*======================================================
# Author: whai
# Last modified: 2015-12-09 12:09
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

const int N = 1e3 + 5;

char str[N];
char tmp[N];

bool ok(char *A, int len) {
	for(int i = 0; i < len; ++i) {
		if(A[i] != A[len - i - 1]) return false;
	}
	return true;
}

bool gao(char *str, int n) {
	int len = strlen(str);
	if(len % n) return false;
	for(int i = 0; i < len; i += len / n) {
		for(int j = i; j < i + len / n; ++j) {
			tmp[j - i] = str[j];
		}
		if(!ok(tmp, len / n)) return false;
	}
	return true;
}

int main() {

	int n;
	scanf("%s", str);
	scanf("%d", &n);
	
	if(!gao(str, n)) puts("NO");
	else puts("YES");

	return 0;
}

