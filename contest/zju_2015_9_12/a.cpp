#include <iostream>
#include <cstdio>
using namespace std;

const int N = 25;
int a[N];

int main() {
	int T;
	int n, c;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &c);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int cnt = 0, die_cnt = 0;
		int p = 0;
		int dir = 0;
		while(cnt < n + 5) {
			cout<<p<<' ';
			if(a[p] > 0) {
				a[p] -= c;
				if(a[p] <= 0) {
					a[p] = 0;
					++die_cnt;
					dir ^= 1;
				}
				++cnt;
				if(die_cnt == n) break;
			}
			if(dir == 0) {
				p = (p + 1) % n;
			} else {
				p = (p - 1 + n) % n;
			}
		}
		cout<<p + 1<<endl;
	}
	return 0;
}
