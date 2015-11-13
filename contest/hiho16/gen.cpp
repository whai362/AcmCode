/*======================================================
# Author: whai
# Last modified: 2015-11-03 20:47
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
#include <ctime>
using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

int main() {
	srand(time(NULL));
	int n = 10;
	cout<<n<<endl;
	for(int i = 0; i < n; ++i) {
		cout<<((LL)(rand() % 100000) * (rand() % 100000)) % 50000000 + 1<<' ';
	}
	cout<<endl;
	return 0;
}

