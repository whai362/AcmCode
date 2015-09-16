#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL __int64

const int N = 1e5 + 5;

int a[N];

bool ok(int x) {
	while(x % 2 == 0) {
		x /= 2;
	}
	while(x % 3 == 0) {
		x /= 3;
	}
	return x == 1;
}

bool gao(int gcd, int n) {
	for(int i = 0; i < n; ++i) {
		if(!ok(a[i] / gcd)) return false;
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	int gcd;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if(i == 0) gcd = a[i];
		else gcd = __gcd(gcd, a[i]);
	}
	if(gao(gcd, n)) puts("Yes");
	else puts("No");
	return 0;
}
