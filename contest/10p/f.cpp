//#define LOCAL
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;


#define MAXN 11000
#define MAXM 55000
#define INF 0x3f3f3f3f


int n, m;
int dfn[MAXN];
int low[MAXN];
int head[MAXN], e;
int stack[MAXN], top;
int instack[MAXN];
int cnt;
int index;
int belong[MAXN];
int out[MAXN];


struct Edge
{
	int to;
	int next;
};


Edge edge[MAXM];


int min(int a, int b)
{
	return a < b ? a : b;
}


void addEdge(int u, int v)
{
	edge[e].to = v;
	edge[e].next = head[u];
	head[u] = e++;
}


void init()
{
	cnt = 1;
	e = 0;
	index = 0;
	int i, j;
	int u, v;
	memset(dfn, -1, sizeof(dfn));
	memset(low, -1, sizeof(low));
	memset(head, -1, sizeof(head));
	memset(instack, 0, sizeof(instack));
	memset(belong, 0, sizeof(-1));
	memset(out, 0, sizeof(out));
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		addEdge(u, v);
	}
}


void tarjan(int u)
{
	int v, i;
	dfn[u] = low[u] = cnt++;
	instack[u] = 1;
	stack[++top] = u;
	for(i = head[u]; i != -1; i = edge[i].next)
	{
		v = edge[i].to;
		if(dfn[v] == -1)
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(instack[v])
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
	
	if(low[u] == dfn[u])
	{
		index++;
		do
		{
			v = stack[top--];	
			instack[v] = 0;
			belong[v] = index;
		}
		while(top != 0 && v != u); 
	}
}


void solve()
{
	int i, j;
	int v;
	int num;
	int ans;
	int tmp;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		init();
		num = 0;
		ans = 0;
		for(i = 1; i <= n; i++)
		{
			if(dfn[i] == -1)
				tarjan(i);
		} 
	
		for(i = 1; i <= n; i++)
		{
			for(v = head[i]; v != -1; v = edge[v].next)
			{
				if(belong[i] != belong[edge[v].to])
				{
					out[belong[i]]++;
				}
					
			}
		}
		
		for(i = 1; i <= index; i++)
		{
			if(!out[i])
			{
				num++;
				tmp = i;
			}
				
		}
		
		if(num == 1)
		{
			for(i = 1; i <= n; i++)
			{
				if(belong[i] == tmp)
					ans++;
			}
			printf("%d\n", ans);
		}
		else
		{
			printf("0\n");
		}
	}
}


int main()
{
#ifdef LOCAL
	freopen("poj2186.txt", "r", stdin);
	// freopen(".txt", "w", stdout);
#endif
	solve();
	return 0;
}
