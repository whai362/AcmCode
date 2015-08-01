#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cnt[4];
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			++cnt[x];
		}
		cout<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<endl;
	}
}
