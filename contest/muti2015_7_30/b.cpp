#include <iostream>
#include <cstdio>
using namespace std;
#define LL __int64
const int N = 1e6 + 6;
int a[N];
void gao(int n) {
	if(n == 0){ puts("0"); return ; }
	int ans = min(2, n);
	int tmp1 = 2, tmp2 = 2;
	for(int i = 2; i < n; ++i) {
		if(2 * a[i - 1] == a[i] + a[i - 2]) {
			++tmp1;
		} else {
			tmp1 = 2;
		}
		if((LL)a[i - 1] * a[i - 1] == (LL)a[i] * a[i - 2]) {
			++tmp2;
		} else {
			tmp2 = 2;
		}
		//cout<<tmp1<<' '<<tmp2<<endl;
		ans = max(ans, max(tmp1, tmp2));
	}
	printf("%d\n", ans);
}
int main() {
	int T;
	scanf("%d", &T);
	int cnt = 0;
	while(T--) {
		++cnt;
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		gao(n);
	}
	return 0;
}
