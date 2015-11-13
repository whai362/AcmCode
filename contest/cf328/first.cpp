/*======================================================
# Author: whai
# Last modified: 2015-11-01 00:25
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

string str[10];

int main() {
	
	int A = 8, B = 8;

	for(int i = 0; i < 8; ++i) {
		cin>>str[i];
	}

	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < str[i].length(); ++j) {
			if(str[i][j] == 'W') {
				int flag = 1;
				for(int k = 0; k < i; ++k) {
					if(str[k][j] != '.') {
						flag = 0;
						break;
					}
				}
				if(flag) {
					A = min(A, i);
				}
			}
			if(str[i][j] == 'B') {
				int flag = 1;
				for(int k = i + 1; k < 8; ++k) {
					if(str[k][j] != '.') {
						flag = 0;
						break;
					}
				}
				if(flag) {
					B = min(B, 7 - i);
				}
			}
		}
	}
	//cout<<A<<' '<<B<<endl;

	if(A <= B) {
		cout<<'A'<<endl;
	} else {
		cout<<'B'<<endl;
	}

	return 0;
}

