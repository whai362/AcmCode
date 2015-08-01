#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define LL __int64
const int MAX_LEN = 100000;
const int N = 1e6 + 5;
char out[N];

bool ok(int n, LL a, LL &b, LL &c) {
	LL x = n + a * a + a + 1;
	for(LL i = a + 1; i * i <= x; ++i) {
		if(x % i == 0) {
			b = i - a - 1;
			c = x / i - a - 1;
			if(b >= 0 && c >= 0 && a + b + c <= min(n, MAX_LEN))
				return true;
		}
	}
	return false;
}

void gao(int n) {
	if(n == 0) {
		puts("0");
		puts("");
		return ;
	}
	LL a = -1, b, c;
	while(1) {
		++a;
		if(ok(n, a, b, c)) break;
	}
	int len = 0;
	for(int i = 0; i < a; ++i) {
		out[len++] = '3';
		out[len++] = ' ';
	}
	for(int i = 0; i < b; ++i) {
		out[len++] = '2';
		out[len++] = ' ';
	}
	for(int i = 0; i < c; ++i) {
		out[len++] = '1';
		out[len++] = ' ';
	}
	--len;
	out[len] = 0;
	printf("%I64d\n", a + b + c);
	//cout<<a<<' '<<b<<' '<<c<<endl;
	//<<' '<<a + b + c<<' '<<a + b + c + a*b + a*c + b*c<<endl;
	puts(out);
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		gao(n);
	}
	return 0;
}
