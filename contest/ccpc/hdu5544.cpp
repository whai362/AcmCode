#include <cstdio>
#include <cstring>

int const maxn = 50100;
int const maxm = 100100;
int next[2 * maxm], head[maxn], end_point[2 * maxm];
long long cost[2 * maxm];
int alloc;

int vis[maxn];
int time_stamp = 1;
long long xs_to_root[maxn];

long long circle[2 * maxm];
int len;

int n, m;

void add_edge(int u, int v, long long c)
{
    end_point[alloc] = v; cost[alloc] = c; next[alloc] = head[u]; head[u] = alloc++;
    end_point[alloc] = u; cost[alloc] = c; next[alloc] = head[v]; head[v] = alloc++;
}

void dfs(int u, long long sum)
{
    xs_to_root[u] = sum;
    vis[u] = time_stamp;
    for (int p = head[u]; p; p = next[p]) {
        int v = end_point[p];
        long long c = cost[p];
        if (vis[v] == time_stamp) {
            long long tmp = xs_to_root[v] ^ sum ^ c;
            if (tmp) circle[++len] = tmp;
        } else
            dfs(v, sum ^ c);
    }
}

int const max_len = 61;
long long lb[max_len + 5];

void liner_base()
{
    memset(lb, 0, sizeof(lb));

    for (int i = 1; i <= len; i++) {
        for (int j = max_len; j >= 0; j--) {
            if ((circle[i] >> j) & 1) {
                if (!lb[j]) { lb[j] = circle[i]; break; }
                else circle[i] ^= lb[j];
            }
        }
    }
}

void init()
{
    alloc = 1;
    time_stamp++;
    for (int i = 0; i <= n; i++) head[i] = 0;
}

const int BZ = 2 << 20;
char Buf[BZ + 1], *buf = Buf;

template <class T>
inline void scan(T &a) // method2: for huge input
{
	bool flag = false;
	for (a = 0; *buf < '0' || *buf > '9'; ++buf)
		if (*buf == '-') flag = true;
	for (; *buf >= '0' && *buf <= '9'; buf++)
		a = a * 10 + (*buf - '0');
	if (flag) a = -a;
}

int main()
{
	//   fread(Buf, 1, BZ, stdin); // way2

    int T;
    scanf("%d", &T);
	// scan(T);
    for (int ti = 1; ti <= T; ti++) {
        printf("Case #%d: ", ti);

        scanf("%d %d", &n, &m);
    //    scan(n); scan(m);
        init();
        for (int i = 0, x, y; i < m; i++) {
            long long z;
            scanf("%d %d %lld", &x, &y, &z);
    //        scan(x); scan(y); scan(z);
            add_edge(x, y, z);
        }

        len = 0;
        dfs(1, 0);

        liner_base();
        
        long long ans = 0;
        for (int i = max_len; i >= 0; i--)
            if (!((ans >> i) & 1)) ans ^= lb[i];
        printf("%lld\n", ans);
    }
}
