/*===================================================================
# Author: whai
#
# Last modified: 2015-10-05 13:42
#
# Filename: poj2533.cpp
===================================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second


const int N = 1e6 + 5;
int	min_v[N]; //存储长度i+1（len）的子序列最大元素的最小值
int LIS(int arr[], int size) {
	int len = 1;
	min_v[0] = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > min_v[len - 1]) { //
			min_v[len++] = arr[i];
		} else {
			int pos = upper_bound(min_v, min_v + len, arr[i] - 1) - min_v;
			min_v[pos] = arr[i];
		}
	}
	return len;
}

int a[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", LIS(a, n));
}

