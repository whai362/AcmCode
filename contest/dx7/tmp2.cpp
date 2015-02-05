#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}

void work()
{

}
int n,m;
int md[210][210];
int mb[210][210];
bool in[210];
int main()
{
    int T,Cas = 0;
    scanf("%d", &T);
    while (Cas ++ < T){
        printf("Case #%d: ", Cas);
        scanf("%d%d", &n, &m);
        memset(md, 0, sizeof(md));
        memset(mb, 0, sizeof(mb));
        int u, v, d, b;
        for (int i = 1; i <= m; i ++){
            scanf("%d%d%d%d", &u, &v, &d, &b);
            md[u][v] = d; 
            mb[u][v] = b;
        }
        int nx = 0, ny = 0;
        memset(in, 0, sizeof(in));

        for (int i = 1; i <= n; i ++){
            if (i == n){
                printf("happy\n");
                break;
            }
            int tmpj = 0,minx = 0,miny = 1000000000;
            for (int j = 1; j <= n; j ++){
                if (!in[j]){
                    int tmpx = nx,tmpy = ny;
                    in[j] = 1;
                    for (int k = 1; k <= n; k ++){
                        if (!in[k]){
                            tmpx += md[j][k];
                            tmpy += md[k][j] + mb[k][j]; 
                        }else {
                            tmpy -= (md[j][k] + mb[j][k]);
                            tmpx -= md[k][j];
                        }
                    }
                    in[j] = 0;
                    if (tmpx - tmpy >= minx - miny){
                        tmpj = j;minx = tmpx;miny = tmpy;
                    }
                }
            }
            if (minx - miny > 0){
                printf("unhappy\n");
                break;
            }
            in[tmpj] = 1;
            if (i != 1 && nx - ny >= minx - miny){
                printf("happy\n");
                break;
            }
            nx = minx;
            ny = miny;
        }
    }
    return 0;
}
