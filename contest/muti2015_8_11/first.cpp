#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2 * 1e6 + 5;
char str[N];
char tmp[15];
void gao(int n, int t) {
	sscanf(str, "%d", n);
	int pre_l = 0, l = 0;
	l = strlen(str);
	int sum = 0;
	for(int i = 0; i < 
}
int main() {
	int n, t;
	while(scanf("%d%d", &n, &t) != EOF) {
		gao(n, t);
	}
	return 0;
}
