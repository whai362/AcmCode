/*======================================================
# Author: whai
#
# Last modified: 2015-10-06 14:52
#
# Filename: bl.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

int u[30], v[30];

int fa[30];

int get_fa(int x) {
	if(x != fa[x]) return fa[x] = get_fa(fa[x]);
}

bool ok(int x) {
	for(int i = 0; i < 30; ++i) {
		fa[i] = i;
	}
	for(int i = 0; i < 21; ++i) {
		if(x & (1 << i)) {
			int fu = get_fa(u[i]);
			int fv = get_fa(v[i]);
			if(fu == fv) return false;
			fa[fv] = fu;
		}
	}
	int an = get_fa(0);
	for(int i = 0; i < 18; ++i) {
		if(get_fa(i) != an) return false;
	}
	return true;
}

int main() {
	u[0]  = 0 ; v[0]  = 1 ;  
	u[1]  = 1 ; v[1]  = 2 ;  
	u[2]  = 2 ; v[2]  = 3 ;  
	u[3]  = 3 ; v[3]  = 4 ;  
	u[4]  = 4 ; v[4]  = 5 ;  
	u[5]  = 5 ; v[5]  = 6 ;  
	u[6]  = 6 ; v[6]  = 7 ;  
	u[7]  = 7 ; v[7]  = 8 ;  
	u[8]  = 8 ; v[8]  = 9 ;  
	u[9]  = 9 ; v[9]  = 10;  
	u[10] = 10; v[10] = 11; 
	u[11] = 11; v[11] = 12; 
	u[12] = 12; v[12] = 13; 
	u[13] = 0 ; v[13] = 13;  
	u[14] = 2 ; v[14] = 11;  
	u[15] = 4 ; v[15] = 9 ;
	u[16] = 6 ; v[16] = 14;
	u[17] = 14; v[17] = 15;
	u[18] = 15; v[18] = 16;
	u[19] = 16; v[19] = 17;
	u[20] = 7 ; v[20] = 17;
	int maxx = (1<<21);
	int ans = 0;
	for(int i = 0; i < maxx; ++i) {
		if(ok(i)) ++ans;
	}
	cout<<ans<<endl;
	return 0;
}

