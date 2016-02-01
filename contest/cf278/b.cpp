/*======================================================
# Author: whai
# Last modified: 2015-12-05 14:44
# Filename: b.cpp
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

int ans[5];
multiset<int> used;

bool ok(vector<int> arr) {
	sort(arr.begin(), arr.end());
	if(arr[0] + arr[3] == 4 * arr[0] && arr[1] + arr[2] == 4 * arr[0])
		return true;
	return false;
}

int a[5];

void deal(int n) {
	sort(a, a + n);
	ans[0] = -1;
	used.clear();
	for(int i = 0; i < n; ++i) {
		used.insert(a[i]);
	}
	if(n == 0) {
		puts("YES");
		ans[0] = 1;
		ans[1] = 1;
		ans[2] = 3;
		ans[3] = 3;
	} else if(n == 1) {
		puts("YES");
		ans[0] = a[0];
		ans[1] = a[0];
		ans[2] = 3 * a[0];
		ans[3] = 3 * a[0];
	} else if(n == 2) {
		vector<int> arr;
		for(int i = 0; i < 4; ++i) {
			arr.PB(a[i]);
		}
		for(int i = 0; i <= 1500; ++i) {
			for(int j = 0; j <=1500; ++j) {
				arr[2] = i;
				arr[3] = j;
				if(ok(arr)) {
					for(int i = 0; i < 4; ++i) {
						ans[i] = arr[i];
					}
					puts("YES");
					break;
				}
			}
			if(ans[0] != -1) break;
		}
		if(ans[0] == -1)
			puts("NO");

	} else if(n == 3) {
		vector<int> arr;
		for(int i = 0; i < 4; ++i) {
			arr.PB(a[i]);
		}
		for(int i = 0; i <= 1500; ++i) {
			arr[3] = i;
			if(ok(arr)) {
				for(int i = 0; i < 4; ++i) {
					ans[i] = arr[i];
				}
				puts("YES");
				break;
			}
		}
		if(ans[0] == -1)
			puts("NO");
	} else {
		if(a[0] + a[3] == 4 * a[0] && a[1] + a[2] == 4 * a[0]) {
			puts("YES");
			for(int i = 0; i < 4; ++i) {
				ans[i] = a[i];
			}
		} else {
			puts("NO");
		}
	}
	if(ans[0] != -1) {
		for(int i = 0; i < 4; ++i) {
			if(used.find(ans[i]) != used.end()) {
				used.erase(used.find(ans[i]));
			} else {
				cout<<ans[i]<<endl;
			}
		}
	}
}

int main() {
	int n;
	while(cin>>n) {
		for(int i = 0; i < n; ++i) {
			cin>>a[i];
		}
		deal(n);
	}
	return 0;
}

