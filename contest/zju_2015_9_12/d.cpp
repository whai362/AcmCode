#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define LL long long

const int N = 1e4 + 5;

int a[N];
int sum_a[N];

LL b[N];
LL sum_b[N];

int l[N], r[N];

void init() {
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		int k;
		LL sum = 0;
		scanf("%d%d", &n, &k);
		init();
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &l[i], &r[i]);
			b[r[i]] = (LL)(1 + r[i] - l[i] + 1) * (r[i] - l[i] + 1) /
				2;
			sum += b[r[i]];
			for(int j = l[i]; j <= r[i]; ++j) {
				a[j] = 1;
			}
		}
		sum_a[0] = 0;
		for(int i = 1; i <= r[n - 1]; ++i) {
			sum_a[i] = sum_a[i - 1] + a[i];
		}
		sum_b[0] = 0;
		for(int i = 1; i <= r[n - 1]; ++i) {
			sum_b[i] = sum_b[i - 1] + b[i];
		}

		//for(int i = 1; i <= r[n - 1]; ++i) {
		//	cout<<sum_a[i]<<' ';
		//}
		//cout<<endl;
		//for(int i = 1; i <= r[n - 1]; ++i) {
		//	cout<<sum_b[i]<<' ';
		//}
		//cout<<endl;

		LL ans = 0;
		int all_need = r[n - 1] - sum_a[r[n - 1]];
		if(k >= all_need) {
			ans = (LL)(1 + r[n - 1]) * r[n - 1] / 2;
		} else {
			for(int i = 0; i < n; ++i) {
				for(int j = i + 1; j < n; ++j) {
					int L = l[i];
					int R = r[j];
					int need = R - L + 1 - (sum_a[R] - sum_a[L - 1]);
					if(need > k) continue;
					else {
						//cout<<L<<' '<<R<<' ';
						int leave = k - need;
						LL tmp = sum - (sum_b[R] -
							sum_b[L - 1]);
						//cout<<tmp<<' ';
						tmp += (LL)(1 + (R - L + 1 +
								 leave)) *
							(R - L + 1 + leave) / 2;
						//cout<<tmp<<endl;
						ans = max(ans, tmp);

					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
