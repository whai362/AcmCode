#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define LL __int64
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int((x).size()))
#define bit(x) (1 << (x))
#define cnt1(x) (__builtin_popcount(x))
const int maxn = 2e5+5;

int n , r;
LL h[maxn] , sum[maxn];
int st[maxn] , ll,rr;

int main(){

    int t; scanf("%d" , &t);
    for(int it=1;it<=t;it++){
        printf("Case #%d:\n" , it);

        scanf("%d%d",&n,&r );
        for(int i=1;i<=n;i++)
            scanf("%I64d" , &h[i]);

        for(int i=1;i<=n;i++) 
            h[i+n] = h[i];
        int m = n+n; sum[0] = 0;
        for(int i=1;i<=m;i++)
            sum[i] = h[i]-(LL)i*r;

        ll = 1 , rr = 0; int nn = n/2;
        LL ans = -1; pair<int,int> choose;
        for(int i=1;i<=m;i++){
            while ( rr>=ll && i-nn>st[ll] )
                ll++;
            //cout<< st[ll]<< ' '<<i <<endl;

            if ( ll<=rr ){
                LL tmp = h[i]+(LL)i*r+sum[ st[ll] ];
                int c1 = i , c2 = st[ll];
                if ( c1>n ) c1 -= n;
                if ( c1>c2 ) swap( c1,c2 );
                if ( ans<tmp ){
                    ans = tmp;
                    choose = make_pair(c1,c2) ;
                } 
                else if ( ans==tmp ){
                    choose = min( choose , make_pair(c1,c2) );
                }
            }
            while ( ll<=rr&& sum[st[rr]]<sum[i] ) rr--;
            st[++rr] = i;
        }
        printf("%d %d\n" , choose.first , choose.second );
    }

    return 0;
}
