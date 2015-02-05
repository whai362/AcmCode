#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef pair<int, int> pii;

#define X first
#define Y second
#define MX 100005
int n, m;
int a[MX], b[MX];
pii x[MX], prv[MX];

void read(int& x) {
    char c;
    
    do c = getchar();
    while (c <= 32);
    for (x = 0; c >= '0'; c = getchar()) x = x * 10 + c - '0';
}

void add(int k, pii pr) {
    for (; k <= m; k += k & -k) x[k] = max(x[k], pr);
}

pii get(int k) {
    pii rlt(0, 0);
    for (; k; k -= k & -k) rlt = max(rlt, x[k]);
    return rlt;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    int i, j, k;
    pii pr, tmp;
    long long rlt;
    
    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; i++) {
            read(a[i]);
            b[i] = a[i];
        }
        sort(b, b + n);
        m = unique(b, b + n) - b;
        fill_n(x + 1, m, pii(0, 0));
        tmp = pii(0, 0);
        for (i = 0; i < n; i++) {
            k = lower_bound(b, b + m, a[i]) - b + 1;
            pr = get(k - 1);
            if (!pr.X) pr.Y = i;
            pr.X++;
            add(k, pr);
            prv[i] = tmp = max(tmp, pr);
			//cout<<tmp.X<<' '<<tmp.Y<<endl;
        }
        rlt = 0;
        for (i = 0; i < n; i++) {
            if (prv[i].X == tmp.X) rlt += prv[i].Y + 1;
        }
        printf("%I64d\n", rlt);
    }
    return 0;
}
