/*======================================================
# Author: whai
# Last modified: 2015-12-07 11:03
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
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 105;
char S1[N], S2[N];
char tab[300];
int main() {

	memset(tab, -1, sizeof(tab));
	tab['A'] = 'U';
	tab['T'] = 'A';
	tab['C'] = 'G';
	tab['G'] = 'C';
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		scanf("%s%s", S1, S2);
		int len = strlen(S1);
		int flag = 1;
		for(int i = 0; i < len; ++i) {
			if(tab[S1[i]] != S2[i]) {
				flag = 0;
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

