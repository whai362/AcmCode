#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int T, N, M, K, L;
int f[100009];
struct T_edge
{
    int b, e;
    T_edge() {}
    T_edge(int b, int e): b(b), e(e) {}
} es[200009];
vector<int> tab[100009];
int inset[100009];
int sensors[100009];
int order[100009];
int getf(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = getf(f[x]);
}
inline void add(int x, int y)
{
    // printf("x=%4d,y=%4d\n",x,y);
    int fx = getf(x), fy = getf(y);
    if (fx == fy)
        return ;
    f[fx] = fy;
}
inline void addnode(int x)
{
    //printf("addnode %4d\n", x);
    inset[x] = 1;
    for (int i = 0; i < tab[x].size(); i++)
        if (inset[es[tab[x][i]].b] && inset[es[tab[x][i]].e])
            add(es[tab[x][i]].b, es[tab[x][i]].e);
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &N, &M, &K);
        for (int i = 1; i <= N; i++)
        {
            inset[i] = 1;
            tab[i].clear();
        }
        for (int i = 1; i <= K; i++)
        {
            scanf("%d", &sensors[i]);
            inset[sensors[i]] = 0;
        }
        for (int i = 1; i <= M; i++)
        {
            scanf("%d%d", &es[i].b, &es[i].e);
            tab[es[i].b].push_back(i);
            tab[es[i].e].push_back(i);
        }
        scanf("%d", &L);
        for (int i = 1; i <= L; i++)
            scanf("%d", &order[i]);
        if (L < K)
        {
            printf("No\n");
            continue;
        }
        //Do it
        int possible = 1;
        for (int i = 1; i <= N; i++)
            f[i] = i;
        for (int i = 1; i <= N; i++)
            if (inset[i])
                addnode(i);
        addnode(order[1]);
        for (int i = 2; i <= L; i++)
        {
            addnode(order[i]);
            if (getf(order[i]) != getf(order[i - 1]))
            {
                // printf("order=%4d\n",order[i] );
                possible = 0;
                break;
            }
            // printf("%d is possible\n",order[i]);
        }
        for (int i = 1; i <= N; i++)
            possible &= (getf(i) == getf(1));
        // for (int i=1;i<=N;i++)
        //  printf("getf[%4d]=%4d\n",i,getf(i));
        printf("%s\n", possible ? "Yes" : "No");
    }
    return 0;
}
