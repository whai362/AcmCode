/*hdu 5046
  题意：
  在N个城市选出K个城市，建飞机场(1 <= N <= 60,1 <= K <= N)，N个城市给出坐标，选择这K个机场，使得从城市到距离自己最近的机场的 最大的距离最小。
  限制：
  1 <= N <= 60; 1 <= K <= N
  思路：
  二分 + 重复覆盖
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int MAXM = 65;
const int MAXN = 65;
const int N = MAXN * MAXM;
const int INF = 0x3f3f3f3f;
struct DLX {
    int n, m, size;
    int U[N], D[N], R[N], L[N], row[N], col[N];
    int H[MAXN], S[MAXM];
    int ans[MAXN], ans_cnt;
    void init(int _n, int _m) {
        ans_cnt = INF;
        n = _n;
        m = _m;
        for (int i = 0; i <= m; i++) {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        for (int i = 1; i <= n; i++)H[i] = -1;
    }
    void link(int r, int c) {
        ++S[col[++size] = c];
        row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if (H[r] < 0)H[r] = L[size] = R[size] = size;
        else {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    void remove(int c) {
        for (int i = D[c]; i != c; i = D[i])
            L[R[i]] = L[i], R[L[i]] = R[i];
    }
    void resume(int c) {
        for (int i = U[c]; i != c; i = U[i])
            L[R[i]] = R[L[i]] = i;
    }
    bool v[MAXM];
    int f() {
        int ret = 0;
        for (int c = R[0]; c != 0; c = R[c])v[c] = true;
        for (int c = R[0]; c != 0; c = R[c])
            if (v[c]) {
                ret++;
                v[c] = false;
                for (int i = D[c]; i != c; i = D[i])
                    for (int j = R[i]; j != i; j = R[j])
                        v[col[j]] = false;
            }
        return ret;
    }
	//注意这些可以加入剪枝优化的
    /*void dance(int d) {
        if (d + f() >= ans_cnt) return;
        if (R[0] == 0) {
            if (d < ans_cnt) ans_cnt = d;
            return ;
        }
        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i])
            if (S[i] < S[c])
                c = i;
        for (int i = D[c]; i != c; i = D[i]) {
            remove(i);
            //ans[d] = row[i];
            for (int j = R[i]; j != i; j = R[j]) remove(j);
            dance(d + 1);
            for (int j = L[i]; j != i; j = L[j]) resume(j);
            resume(i);
        }
    }*/

	bool dance(int d, int limit) {
		if (d + f() > limit) return false;
        if (R[0] == 0) return d <= limit;
        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i])
            if (S[i] < S[c])
                c = i;
        for (int i = D[c]; i != c; i = D[i]) {
            remove(i);
            for (int j = R[i]; j != i; j = R[j]) remove(j);
            if(dance(d + 1, limit)) return true;
            for (int j = L[i]; j != i; j = L[j]) resume(j);
            resume(i);
        }
		return false;
    }
} dlx;

P a[N];


LL _abs(int x) {
    if(x < 0) return -x;
    return x;
}

LL dis(P a, P b) {
    return _abs(a.X - b.X) + _abs(a.Y - b.Y);
}

bool ok(LL d, int n, int k) {
    dlx.init(n, n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(dis(a[i], a[j]) <= d) {
                dlx.link(i + 1, j + 1);
            }
        }
    }
    return dlx.dance(0, k);
}

void gao(int n, int k) {
    LL L = 0, R = 4 * 1e9, ans = 4 * 1e9;
    while(L < R) {
        LL mid = (L + R) >> 1;
        if(!ok(mid, n, k)) {
            L = mid + 1;
        } else {
            ans = min(ans, mid);
            R = mid;
        }
    }
    if(ok(L, n, k)) ans = min(ans, L);
    if(ok(R, n, k)) ans = min(ans, R);
    printf("%I64d\n", ans);
}

int main() {
    int T;
    int cas = 0;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].X, &a[i].Y);
        }
        printf("Case #%d: ", ++cas);
        gao(n, k);
    }
    return 0;
}
