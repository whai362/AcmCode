/*======================================================
# Author: whai
# Last modified: 2015-12-09 12:36
# Filename: c1.cpp
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


int m;

void get_AB(int h, int a, int x, int y, LL &A, LL &B) {
	LL tmp = h;
	A = 0;
	for(int i = 1; i <= m; ++i) {
		tmp = (tmp * x + y) % m;
		++A;
		if(tmp == a) break;
	}
	if(tmp != a) ++A;
	tmp = a;
	B = 0;
	for(int i = 1; i <= m; ++i) {
		tmp = (tmp * x + y) % m;
		++B;
		if(tmp == a) break;
	}
	if(tmp != a) ++B;
}

int main() {
	int h[2], a[2], x[2], y[2];
	cin>>m;
	
	for(int i = 0; i < 2; ++i) {
		cin>>h[i]>>a[i]>>x[i]>>y[i];
	}
	int flag = 0;
	if(h[0] == a[0] && h[1] == a[1]) {
		flag = 1;
		puts("0");
	} else {
		LL A[2], B[2];
		for(int i = 0; i < 2; ++i) {
			get_AB(h[i], a[i], x[i], y[i], A[i], B[i]);
		}
		//cout<<A[0]<<' '<<B[0]<<' '<<A[1]<<' '<<B[1]<<endl;
		if(A[0] == m + 1 || A[1] == m + 1) {
		
		} else if(A[0] == A[1]) {
			cout<<A[0]<<endl;
			flag = 1;
		} else if(B[0] == m + 1 || B[1] == m + 1) {
			if(B[0] != m + 1 || B[1] != m + 1) {
				if(B[0] != m + 1) {
					swap(A[0], A[1]);
					swap(B[0], B[1]);
				}
				if(A[0] >= A[1] && (A[0] - A[1]) % B[1] == 0) {
					cout<<A[0]<<endl;
					flag = 1;
				}
			}
		} else {
			for(int i = 0; i <= m; ++i) {
				LL left = A[0] + i * B[0];
				if(left >= A[1]) {
					if((left - A[1]) % B[1] == 0) {
						flag = 1;
						cout<<left<<endl;
						break;
					}
				}
			}
		}
	}
	if(!flag) puts("-1");

	return 0;
}

