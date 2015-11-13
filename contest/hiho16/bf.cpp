#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include <vector>
using namespace std;
typedef long long LL;

const int MOD = 1e6 + 7;

const int N=10000;
LL a[N],s[N],n;
long long ans[N];

vector<pair<LL, int> > dict[MOD + 1];

void add(LL x, int v) {
	int key = x % MOD;
	for (int i = 0; i < (int)dict[key].size(); i++) {
		if (dict[key][i].first == x) {
			dict[key][i].second += v;
			return ;	
		}	
	}
	
	dict[key].push_back(make_pair(x, v));
}

int get(LL x) {
	int key = x % MOD;
	for (int i = 0; i < (int)dict[key].size(); i++) {
		if (dict[key][i].first == x) {
			return dict[key][i].second;
		}
	}
	return 0;
}

void work(LL x)
{
	s[0]=0;
	//mm.clear();
	for(int i=1;i<=2 * n;i++)
	{
		s[i]=(s[i-1]+a[i]) % x;
	}
	
	int ret = 0;
	for (int l = 1, r = 1; l <= n; l++) {
		while (l + n > r) {
			add(s[r], 1); //dict[s[r] % MOD]++;
			r++;
		}
		ret = max(ret, get(s[l - 1]));
		add(s[l], -1);
	}
	
	for (int i = 1; i <= 2 * n; i++) {
		dict[s[i] % MOD].clear();
	}
	/*
	for(int i=1;i<=n;i++)
		mm[s[i]]++;
	int tmp=0;
	for(int i=0;i<n;i++)
	{
		tmp=max(tmp,mm[s[i]]);
		mm[s[i+1]]--;
		mm[s[i+n+1]]++;
	}
	*/
	//cout << x << " " << ret << endl;
	for (int i = 1; i <= ret; i++) {
		ans[i] = max(ans[i], x);
	}
}
int main()
{
	cin >> n;
	LL sum=0;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[i] = a[i + n] = x;
		sum += a[i];
		ans[i]=0;
	}
	for (int i = 1; 1LL * i * i <= sum; i++) {
		if (sum % i == 0) {
			work(i);
			work(sum / i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", ans[i]);
	}
}
