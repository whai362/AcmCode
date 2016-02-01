/*======================================================
# Author: whai
# Last modified: 2015-12-08 13:47
# Filename: gen.cpp
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
#include <cstdlib>
#include <ctime>
using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

int main() {
	srand(time(NULL));
	int n, m;
	n = 10, m = 1000;
	cout<<n<<' '<<m<<endl;
	for(int i = 0; i < m; ++i) {
		int a = rand() % 10 + 1;
		cout<<a<<' ';
	}
	cout<<endl;
	return 0;
}

