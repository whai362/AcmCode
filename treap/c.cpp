#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define PB push_back

const int N = 1e5 + 5;

vector<int> G[N];

int ch_cnt[N];

int no_root = 0;

bool dfs(int u, int fa, int root) {
    //cout<<u<<' '<<G[1].size()<<endl;
    if(u != root && G[u].size() == 1) {
        ch_cnt[u] = 1;
        return true;
    }
    ch_cnt[u] = 0;
    int cnt = 0;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(v == fa) continue;
        if(dfs(v, u, root) == false) {
			no_root = v;
            return false;
        }
        if(ch_cnt[v] > 2 || (ch_cnt[v] == 2 && G[v].size() <= 2)) ++cnt;
        ch_cnt[u] += ch_cnt[v];
    }
    if(u == root && cnt <= 2) return true;
    if(u != root && cnt <= 1) return true;
    return false;
}

void gao(int n) {
    if(dfs(1, -1, 1)) puts("Yes");
    else {
		memset(ch_cnt, 0, sizeof(ch_cnt));
		//cout<<"!!!!!"<<endl;
		if(no_root && dfs(no_root, -1, no_root)) puts("Yes");
		else puts("No");
	}
    //for(int i = 1; i <= n; ++i) {
    //  cout<<ch_cnt[i]<<' ';
    //}
    //cout<<endl;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].PB(v);
        G[v].PB(u);
    }
    gao(n);
    return 0;
}
