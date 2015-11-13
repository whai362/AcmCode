/*======================================================
# Author: whai
# Last modified: 2015-10-28 11:29
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

char A[15], B[15];

int main() {
	scanf("%s", A);
	scanf("%s", B);
	int flag = 1;
	int len = strlen(A);
	for(int i = 0; i < len; ++i) {
		int tmp = A[i] - B[i];
		if(tmp < 0) tmp = -tmp;
		if(flag == 1 && tmp == 0) {
			continue;
		}
		flag = 0;
		printf("%d", tmp);
	}
	if(flag) {
		cout<<0<<endl;
	}
	return 0;
}

