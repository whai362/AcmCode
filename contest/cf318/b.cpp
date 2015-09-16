#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

#define LL __int64

int h[N];

int d[N];

void deal(int id) {
	if(id == 0) d[id] = min(d[id], 1);
	else {
		d[id] = min(d[id], min(d[id - 1] + 1, h[id]));
	}
}

void deal1(int id, int n) {
	if(id == n - 1) d[id] = min(d[id], 1);
	else {
		d[id] = min(d[id], min(d[id + 1] + 1, h[id]));
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &h[i]);
	}
	int ans = 1;
	for(int i = 0; i < n; ++i) {
		d[i] = N;
	}
	for(int i = 0; i < n; ++i) {
		deal(i);
	}
	for(int i = n - 1; i >= 0; --i) {
		deal1(i, n);
	}
	for(int i = 0; i < n; ++i) {
		ans = max(ans, d[i]);
		//cout<<d[i]<<' ';
	}
	//cout<<endl;
	cout<<ans<<endl;
	return 0;
}
