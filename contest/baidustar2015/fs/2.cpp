/*whai
 */
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <cassert>
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const int maxn = 5005;
const int maxs = 30;
const int inf = 1e9+7;

int n;
int a[maxn][5] , b[maxn][5];
int dp[maxn][30];
int p[4] , p2[4];

bool judge(int i, int p[]){
    bool f = true;
    for(int j=1;j<=3;j++)
        if ( b[i][ p[j] ]>b[i][ p[j+1] ] ){
            f = false; break;
        }
    return f;
}

int main(){

    int t; scanf("%d" , &t);
    for(int it=1;it<=t;it++){
        printf("Case #%d:\n" , it);

        memset(dp,0,sizeof(dp));
        for(int i=1;i<=4;i++) a[0][i] = 0 , b[0][i] = i;
        for(int i=0;i<30;i++) dp[0][i] = inf;
        dp[0][0] = 0;

        scanf("%d" , &n);
        int ans = inf;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=4;j++)
                scanf("%d%d", &a[i][j],&b[i][j]);

            for(int j=1;j<=4;j++) p[j] = j; int k = 0;
            do {   
                dp[i][k] = inf;
                if ( !judge(i,p) ) continue;

                for(int j=1;j<=4;j++) p2[j] = j; int k1 = 0;
                do{ 
                    if ( !judge(i-1,p2) ) continue;

                    if ( dp[i-1][k1]<inf ){
                        int sum = 0;
                        for(int j=1;j<=4;j++)
                            sum +=  abs( a[i-1][p2[j]]-a[i][p[j]] ) +
                                    abs( b[i-1][p2[j]]-b[i][p[j]] );
                        dp[i][k] = min(dp[i][k] , 
                            dp[i-1][k1] + sum );
                    }
                    k1++;
                }while( next_permutation(p2+1,p2+5) );

                if ( i==n ){
                    ans = min( ans , dp[i][k] );
                }
                k++;
            }while( next_permutation(p+1,p+5) );
        }
        printf("%d\n" , ans);


    }

    return 0;
}
