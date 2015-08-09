#include <iostream>
#include <cstdio>
using namespace std;
#define LL __int64
const int N = 65;
LL a[N];
LL b[N];
void predo(int n) {
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 5;

	b[0] = 1;
	b[1] = 1;
	b[2] = 2;
	for(int i = 4; i < N; ++i) {
		b[i - 1] = b[i - 2] + b[i - 4];
		a[i] = a[i - 1] + b[i - 1];
	}
}
int main() {
	predo(N);
	int n;
	while(scanf("%d", &n) != EOF) {
		cout<<a[n - 1]<<endl;
	}
}
