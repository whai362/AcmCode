/*======================================================
# Author: whai
# Last modified: 2016-01-17 16:16
# Filename: c.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;

LL c[N];

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		int n;
		LL A, B;
		scanf("%d%lld%lld", &n, &A, &B);

		LL sum = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%lld", &c[i]);
			sum += c[i];
		}
		//cout<<sum<<endl;

		double ans = 0;
		LL pre = 0;

		LL len = B - A;

		for(int i = 0; i < n; ++i) {
			LL L = A / sum;
			if(A % sum) {
				LL d = A - (L * sum);
				if(d <= pre + c[i]) d = pre + c[i] - max(pre, d);
				else d = 0;
				ans += (double)(c[i] - d + c[i]) * d / (2 * len);
				++L;
			}
			LL R = B / sum;
			//cout<<'!'<<L<<' '<<R<<endl;
			ans += (double)(R - L) * c[i] * c[i] / (2 * len);
			LL d = B - R * sum;
			if(pre <= d) d = min(pre + c[i], d) - pre;
			else d = 0;
			ans += (double)d * d / (2 * len);
			pre += c[i];
			//cout<<c[i]<<' '<<tmp<<endl;
		}
		//cout<<ans<<endl;
		printf("Case #%d: %.9lf\n", ++cas, ans);
	}
	return 0;
}
