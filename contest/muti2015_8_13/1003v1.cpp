#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL __int64
int n = 1000;

LL lcm(int i, int j) {
	return (LL)i * j / __gcd(i, j);
}

LL f(int n) {
	LL s1 = 0;
	for(int i = 1; i <= n; ++i) {
		s1 += (lcm(i, i) + __gcd(i, i) >= n);
	}
	LL s2 = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			if(i * j <= n * n)
				s2 += (lcm(i, j) + __gcd(i, j) >= n);
			else{
				s2 += n - j - 1;
				break;
			}
		}
	}
	return s1 + s2 * 2;
}

int main() {
	cout<<f(100000)<<endl;
}
