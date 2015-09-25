#include <iostream>
#include <cstdio>
#include <tr1/unordered_map>
#include <vector>
using namespace std;
using namespace std::tr1;

#define LL __int64
#define PB push_back
#define X first
#define Y second
#define P pair<LL, int>

unordered_map<LL, int> mp;
vector<P> dp[2];

const int N = 2 * 1e5 + 5;

LL a[N];

int main() {
	int n, k, x;
	cin>>n>>k>>x;
	for(int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	LL tmp = a[0];
	for(int i = 0; i <= k; ++i) {
		dp[0].PB(P(tmp, i));
		tmp *= x;
	}

	int now = 0;

	for(int i = 1; i < n; ++i) {
		dp[now ^ 1].clear();
		mp.clear();
		for(int j = 0; j < dp[now].size(); ++j) {
			P d = dp[now][i];
			tmp = a[1];
			for(int l = 0; l + d.Y <= k; ++i) {
				if(mp.find(d.X | tmp) == mp.end() || mp[d.X | tmp] > l + d.Y) {
					mp[d.X | tmp] = l + d.Y;
					dp[now ^ 1].PB(P(d.X | tmp, l + d.Y));
				}
			}
		}
	}
	LL ans = 0;
	for(int i = 0; i < dp[now].size(); ++i) {
		ans = max(ans, dp[now][i].X);
	}
	cout<<ans<<endl;
	return 0;
}
