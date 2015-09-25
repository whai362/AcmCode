#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define LL __int64

int main() {
	int n;
	for(int i = 0; i < 10; ++i) {
		cout<<pow(5 + 2 * sqrt(6.0), 1 + (1<<i))<<endl;
	}
	return 0;
}
