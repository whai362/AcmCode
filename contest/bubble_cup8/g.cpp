#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;


const int INF = 0x3f3f3f3f;
const int N = 100005;
#define PB push_back

struct E {
	int v;
	int c;
};

vector<E> G[N];
int level[N];
void bfs(int end) {
	memset(level, 0, sizeof(level));
	queue<int> q;
	q.push(end);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < G[now].size(); ++i) {
			int ch = G[now][i].v;
			if (level[ch] == 0 && ch != end) {
				level[ch] = level[now] + 1;
				q.push(ch);
			}
		}
	}
}

int pre[N];
int step[N];
int mask[N];
void bfs1(int S) {
	memset(pre, -1, sizeof(-1));
	memset(step, 0x3f, sizeof(step));
	queue<int> q;
	q.push(S);
	step[S] = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		int flag = 1;
		for (int i = 0; i < G[now].size(); ++i) {
			int ch = G[now][i].v;
			int c = G[now][i].c;
			if(c) continue;
			if(ch == S) continue;
			if(step[ch] != INF) continue;
			step[ch] = step[now] + 1;
			pre[ch] = now;
			q.push(ch);
			flag = 0;
		}
		mask[now] = flag;
	}
}

int path[N];
int minn[N];
int used[N];
void dij(int u) {
	memset(path, 0x3f, sizeof(path));
	memset(minn, 0x3f, sizeof(minn));
	queue<E> q;
	q.push((E) { u, 0 });
	//used[0] = n;
	while (!q.empty()) {
		E now = q.front();
		q.pop();
		int now_level = level[now.v];
		if (now.c > path[now_level])
			continue;
		for (int i = 0; i < G[now.v].size(); ++i) {
			E ch = G[now.v][i];
			if(ch.v == u) continue;
			if (level[ch.v] == now_level - 1 && ch.c <= path[now_level - 1]) {
				path[now_level - 1] = ch.c;
				used[now_level - 1] = ch.v;
				//cout<<now_level - 1<<' '<<used[now_level - 1]<<endl;
				if (ch.c < minn[ch.v]) {
					minn[ch.v] = ch.c;
					q.push(ch);
				}
			}
		}
	}
}

void init(int n) {
	for (int i = 1; i <= n; ++i)
		G[i].clear();
}

string ans = "", tmp;
vector<int> lj, tmp_lj;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		++u, ++v;
		G[u].PB((E) { v, c });
		G[v].PB((E) { u, c });
	}
	bfs1(n);
	bfs(1);
	
	//for(int i = 1; i <= n; ++i) {
	//	cout<<step[i]<<' ';
	//}
	//cout<<endl;

	for(int u = 1; u <= n; ++u) {
		if(u != n && mask[u] == 0) continue;
		dij(u);
		tmp = "";
		for (int i = level[u] - 1; i >= 0; --i) {
			tmp += char(path[i] + '0');
		}
		if(tmp == "") tmp = "0";

		tmp_lj.clear();
		for (int i = 0; i < level[u]; ++i) {
			tmp_lj.PB(used[i] - 1);
		}
		int tmp_u = u;
		while(pre[tmp_u] != -1) {
			tmp_lj.PB(tmp_u - 1);
			tmp_u = pre[tmp_u];
		}
		tmp_lj.PB(tmp_u);
		
		//cout<<'!'<<u<<' '<<tmp<<endl;

		if(ans == "" || ans > tmp) {
			ans = tmp;
			lj = tmp_lj;
		} else if(ans == tmp && lj.size() > tmp_lj.size()) {
			lj = tmp_lj;
		}
	}
	cout<<ans<<endl;
	cout<<lj.size() - 1<<endl;
	for(int i = 0; i < lj.size() - 1; ++i) {
		cout<<lj[i]<<' ';
	}
	cout<<endl;
	return 0;
}
