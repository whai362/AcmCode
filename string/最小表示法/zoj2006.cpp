/*======================================================
# Author: whai
# Last modified: 2015-10-14 00:47
# Filename: zoj2006.cpp
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

const int N = 1e5 + 5;

int MR(char *s, int len) {
    int i = 0, j = 1, cnt = 0;
    while (i < len && j < len && cnt < len) {
        if(s[(i + cnt) % len] == s[(j + cnt) % len])
            cnt++;
        else {
            if (s[(i + cnt) % len] > s[(j + cnt) % len]) 
                 i = i + cnt + 1;
            else
                 j = j + cnt + 1;
            if (i == j) ++j;
            cnt = 0;
        }
    }
    return min(i,j);
}

char str[N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", str);
		printf("%d\n", MR(str, strlen(str)) + 1);
	}
	return 0;
}

