/*codeforces 526 c Om Nom and Candies
  题意：
  给出一个容量为c背包，两种物品的价值hr,hb和容量cr,cb，求装满背包能装的最大价值。
  限制：
  1 <= c,hr,hb,wr,wb <= 1e9
  思路：
  剩余系
  设第一种物品有x个，第二种物品有y个，则有：
  x*hr + y*hb <= c
  则有：
  (c-y*hb) % hr = t
  不难看出对于同一个剩余系t，最优值在两端。
  所以求出所有剩余系，比较最优值，得到全局最优。
  复杂度O(sqrt(n))
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int N = 1000000;
#define LL __int64
map<LL, int> mp;
int a[N], r[N], cnt;
int main() {
	LL c, Hr, Hb, Wr, Wb;
	cin >> c >> Hr >> Hb >> Wr >> Wb;
	if (Wr < Wb) {
		swap(Hr, Hb);
		swap(Wr, Wb);
	}
	cnt = 0;
	LL lim = min(Wb + 1, c / Wr + 1);
	for (int i = 0; i <= lim; ++i) {
		LL tmp = ((c - Wr * i) % Wb + Wb) % Wb;
		if (mp.find(tmp) == mp.end()) {
			r[cnt] = tmp;
			a[cnt++] = i;
			mp[tmp] = 1;
		}
	}
	LL ans = 0;
	if (Hr * Wb <= Hb * Wr) {
		for (int i = 0; i < cnt; ++i) {
			LL tmp = Wr * a[i];
			if (tmp > c) continue;
			ans = max(ans, Hr * a[i] + (c - tmp) / Wb * Hb);
		}
	}
	else {
		for (int i = 0; i < cnt; ++i) {
			LL d = __gcd(Wr, Wb);
			LL nn = (c / Wr - a[i]) / (Wb / d);
			nn = nn * Wb / d + i;
			LL tmp = nn * Wr;
			if (tmp > c) continue;
			ans = max(ans, Hr * nn + (c - tmp) / Wb * Hb);
		}
	}
	cout << ans << endl;
	return 0;
}
