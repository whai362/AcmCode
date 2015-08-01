#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>

struct edge
{
    int from, to, index;
    long long c;
};

long long const big = 100000;
int const maxn = 2005;
int const maxm = 60006;
int n, m, min_len;

std::vector<std::vector<edge> > graph;
std::vector<std::vector<edge> > g2;

long long const inf = 1000000000000000LL;
long long dist[maxn];
bool visited[maxn];

long long spfa(int source, int target, std::vector<std::vector<edge> > const & g)
{
    std::fill(dist, dist+n, inf);
    std::deque<int> relaxed;
    relaxed.push_back(source);
    dist[source] = 0;
    visited[source] = true;
    while (!relaxed.empty()) {
        int x = relaxed.front();
        relaxed.pop_front();

        for (int i = 0; i < (int)g[x].size(); i++) {
            int v = g[x][i].to, e = g[x][i].c;
            if (dist[v] > dist[x] + e) {
                dist[v] = dist[x] + e;
                if (!visited[v]) {
                    if (!relaxed.empty() && dist[v] < dist[relaxed.front()])
                        relaxed.push_front(v);
                    else
                        relaxed.push_back(v);
                    visited[v] = true;
                }
            }
        }
        visited[x] = false;
    }
    return dist[target];
}


int const capacity_inf = 1<<27;
template <class T>
struct dinic
{
    typedef T value_type;
    typedef int size_type;

    struct dinic_edge {
        size_type from, to;
        value_type capacity, flow;
    };

    dinic(size_type num) : size(num)
    {
        graph.resize(num);    //[0, num)
        dist.resize(num);    //[0, num)
    }

    void add_edge(int u, int v, value_type cap)
    {
        dinic_edge tmp;
        tmp.from = u; tmp.to = v; tmp.capacity = cap; tmp.flow = 0;
        edges.push_back(tmp);
        graph[u].push_back(edges.size() - 1);

        tmp.from = v; tmp.to = u; tmp.capacity = 0; tmp.flow = 0;
        edges.push_back(tmp);
        graph[v].push_back(edges.size() - 1);
    }

    bool bfs_label(size_type source, size_type target)
    {
        std::fill(dist.begin(), dist.end(), -1);
        std::queue<size_type> q;
        q.push(source);
        dist[source] = 0;
        while (!q.empty()) {
            size_type now = q.front();
            q.pop();
            for (std::vector<size_type>::iterator it = graph[now].begin(); it != graph[now].end(); ++it) {
                dinic_edge e = edges[*it];
                if (dist[e.to] == -1 && e.capacity > e.flow) {
                    q.push(e.to);
                    dist[e.to] = dist[now] + 1;
                }
            }
        }
        return dist[target] != -1;
    }

    value_type dfs(size_type v, size_type target, value_type f)
    {
        if (v == target || !f) return f;
        value_type block_flow = 0;
        for (std::vector<size_type>::iterator it = graph[v].begin(); it != graph[v].end(); ++it) {
            dinic_edge & e = edges[*it];
            if (e.capacity > e.flow && dist[e.to] == dist[v] + 1) {
                value_type tmp = dfs(e.to, target,
                        std::min(e.capacity - e.flow, f - block_flow));
                block_flow += tmp;
                e.flow += tmp;
                edges[(*it) ^ 1].flow -= tmp;
            }
        }
        if (!block_flow) dist[v] = -1;
        return block_flow;
    }

    value_type max_flow(size_type source, size_type target)
    {
        value_type flow = 0;
        for (int tmp; bfs_label(source, target); )
            while ((tmp = dfs(source, target, capacity_inf))) flow += tmp;
        return flow;
    }

//private:
    size_type size;
    std::vector<int> dist;
    std::vector<dinic_edge> edges;
    std::vector<std::vector<size_type> > graph;
};


bool vis_edge[maxm];
void init_graph_dfs(dinic<int> & d, int x)
{
    if (x == 0) return;
    for (int i = 0; i < (int)graph[x].size(); i++) {
        edge t = graph[x][i];
        if (vis_edge[t.index]) continue;
        if (dist[x] == dist[t.to] + t.c) {
            //    std::cerr << "---->" << t.index << ' ' << t.from + 1 << ' ' << x + 1 << '\n';
            d.add_edge(t.to, x, 1);
            vis_edge[t.index] = true;
            init_graph_dfs(d, t.to);
        }
    }
}

int main()
{
    for (int x, y, c; std::scanf("%d%d", &n, &m) != EOF; ) {
        graph.clear(); graph.resize(n);
        g2.clear(); g2.resize(n);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &c);
            x--; y--;
            edge tmp; tmp.index = i;
            tmp.to = y; tmp.c = c;
            graph[x].push_back(tmp);
            tmp.to = x; tmp.c = c;
            graph[y].push_back(tmp);

            tmp.to = y; tmp.c = big * c + 1;
            g2[x].push_back(tmp);
            tmp.to = x; tmp.c = big * c + 1;
            g2[y].push_back(tmp);
        }

        int ans1, ans2;
        min_len = spfa(0, n-1, g2) % big;
        ans2 = m - min_len;

        //int min_path =
        spfa(0, n-1, graph);

        //init_flow_graph
        dinic<int> d(n);
        int s = 0, t = n-1;
        std::memset(vis_edge, 0, sizeof(vis_edge));
        init_graph_dfs(d, t);
        ans1 = d.max_flow(s, t);
        std::printf("%d %d\n", ans1, ans2);
    }
}
