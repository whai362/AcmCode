/*======================================================
# Author: whai
# Last modified: 2015-12-10 00:24
# Filename: b.cpp
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
#include <tr1/unordered_set>
using namespace std;
using namespace std::tr1;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;

pair<P, int> a[N];

bool cmp(pair<P, int> a, pair<P, int> b) {
    if(a.X.X == b.X.X) return a.X.Y > b.X.Y;
    return a.X.X < b.X.X;
}

vector<int> V;
P ans[N];
unordered_set<LL> used;

LL get_id(LL a, LL b) {
    return a * N + b;
}

P pool[N];
int st, en;

int cur_i, cur_j, cur_v;
bool gao(int n, int m) {
    sort(a, a + m, cmp);

    V.clear();
    used.clear();
    cur_i = 0, cur_j = 0; cur_v = 1;
	st = en = 0;
    int hav = 0;
	int cnt = 0;
    for(int k = 0; k < m; ++k) {
        //cout<<a[k].Y<<endl;
        if(a[k].X.Y == 0) {
            if(hav == 0) {
                return false;
            } else {
				ans[a[k].Y] = pool[st++];
				--hav;
            }
        } else {
			++cnt;
            if(V.size() == 0) {
                ans[a[k].Y] = P(1, 2);
                //cout<<'!'<<a[k].Y<<' '<<1<<' '<<2<<endl;
                used.insert(get_id(1, 2));
                V.PB(cur_v++);
                V.PB(cur_v++);
            } else {
                hav += V.size() - 1;
				if(en <= m)
					for(int i = 0; i < V.size() - 1 && en <= m; ++i) {
						pool[en++] = P(V[i], cur_v);
					}
                ans[a[k].Y] = P(V[V.size() - 1], cur_v);
                //cout<<'!'<<a[k].Y<<' '<<V[V.size() - 1]<<' '<<cur_v<<endl;
                used.insert(get_id(V[V.size() - 1], cur_v));
                V.PB(cur_v++);
            }
        }
    }
    return (cnt == n - 1) && true;
}

int main() {
    int n, m;
    
    while(scanf("%d%d", &n, &m) != EOF) {
        
        for(int i = 0; i < m; ++i) {
            scanf("%d%d", &a[i].X.X, &a[i].X.Y);
            a[i].Y = i;
        }
        if(gao(n, m)) {
            for(int i = 0; i < m; ++i) {
                printf("%d %d\n", ans[i].X, ans[i].Y);
            }
        } else {
            puts("-1");
        }
    }

    return 0;
}
