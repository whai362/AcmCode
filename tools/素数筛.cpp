/*素数筛
  一个有用的性质：1~n的素数只需要用1~sqrt(n)的素数来筛，这个性质在局部筛的情况下很有用。
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
#define LL __int64
const int N = 1000000;
bool is_pri[N];
int pri[N], tot;
void get_pri(int n) {
	tot = 0;
	memset(is_pri, 1, sizeof(bool) * (n + 1));
	is_pri[0] = is_pri[1] = 0;
	for (int i = 2; i <= n; ++i)
		if (is_pri[i]) {
			if (n / i < i) break;
			for (int j = i * i; j <= n; j += i) is_pri[j] = false;
		}
	for (int i = 2; i <= n; ++i) if (is_pri[i]) pri[tot++] = i;
}
//O(n)
//void get_pri(int n){
//	tot=0;
//	memset(is_pri, 1, sizeof(is_pri));
//	for(int i = 2; i <= n; ++i){
//		if(is_pri[i]) pri[tot++] = i;
//		for(int j = 0; j < tot && i * pri[j] <= n; ++j){
//			is_pri[i * pri[j]] = 0;
//			if(i % pri[j] == 0) break;	//这里break掉是因为pri[j]可以把i后面的覆盖掉
//		}
//	}
//}
int main() {
	double st = clock(), en;
	get_pri(N - 1);
	for (int i = 0; i < tot; ++i) {
		cout << pri[i] << ' ';
	}
	cout << endl;
	en = clock();
	cerr << double(en - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
