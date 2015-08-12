#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define eps 1e-8
#define x first
#define y second
const int MAXN = 2 * 100005;
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
int s[MAXN];
int len[MAXN];

void Manacher(int s[], int len[], int n) {
    memset(len, 0, sizeof(len));
    for (int i = 0, j = 0, k; i < 2 * n; i += k, j = Max(j - k, 0)) {
        while (i - j >= 0 && i + j + 1 < 2 * n && s[(i - j) / 2] == s[(i + j + 1) / 2]) j ++;
        len[i] = j;
        for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] < j - k; k ++) {
            len[i + k] = Min(len[i - k], j - k);
        }
    }
}

struct Dt {
	int p, r;
}a[MAXN];

bool cmp(Dt a, Dt b) {
	return a.r > b.r;
}

set<int> myset;

void gao(int n) {
	Manacher(s, len, n);
	for(int i = 1; i < 2 * n; ++i) {
		a[i / 2] = (Dt){i / 2, len[i] / 2};
	}
	//cout<<endl;
	//for(int i = 0; i < n; ++i) {
	//	cout<<a[i].p<<' '<<a[i].r<<endl;
	//}
	sort(a, a + n, cmp);
	myset.insert(a[0].p);
	int ans = 0;
	set<int> :: iterator lp, rp;
	for(int i = 1; i < n; ++i) {
		int l = a[i].p - a[i].r;
		int r = a[i].p + a[i].r;
		//cout<<"?"<<a[i].p<<' '<<l<<' '<<r<<endl;
		if(l >= r){
			myset.insert(a[i].p);
			continue;
		}
		lp = myset.lower_bound(l);
		if(lp == myset.end()) {
			myset.insert(a[i].p);
			continue;
		}
		//cout<<"?"<<endl;
		rp = myset.upper_bound(r);
		if(rp == myset.begin()) {
			myset.insert(a[i].p);
			continue;
		}
		--rp;
		int lv = *lp;
		int rv = *rp;
		//cout<<"!"<<lv<<' '<<rv<<endl;
		ans = max(ans, max((a[i].p - lv), (rv - a[i].p)) * 3);
		myset.insert(a[i].p);
	}
	cout<<ans<<endl;
}

void init(int n) {
	myset.clear();
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		int n;
		scanf("%d", &n);
		init(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &s[i]);
		}
		printf("Case #%d: ", ++cas);
		gao(n);
	}
	return 0;
}
