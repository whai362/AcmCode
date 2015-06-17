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
const int maxn = 55;

int n;
struct XY{
    int x1,x2,y1,y2;
    XY(){}
    XY(int a,int b,int c,int d){
        x1 = a , y1 = b , x2 = c , y2 = d;
    }
}xx[maxn] , yy[maxn];
int xn, ynn;

int main(){

    int t; scanf("%d" , &t);
    for(int it=1;it<=t;it++){
        printf("Case #%d:\n" , it);

        scanf("%d",&n);
        xn = ynn = 0;
        for(int i=1;i<=n;i++){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d" , &x1,&y1,&x2,&y2);
            if ( x1>x2 ) swap(x1,x2);
            if ( y1>y2 ) swap(y1,y2);
            if ( x1==x2 ){
                xx[++xn] = XY(x1,y1,x2,y2);
            }
            if ( y1==y2 ){
                yy[++ynn] = XY(x1,y1,x2,y2);
            }
        }

        int ans = 0;
        for(int i=1;i<=xn;i++)
            for(int j=i+1;j<=xn;j++){
                int y1 = max(xx[i].y1 , xx[j].y1);
                int y2 = min(xx[i].y2 , xx[j].y2);
                if ( y1>=y2 ) continue;

                for(int k=1;k<=ynn;k++)
                    for(int h=k+1;h<=ynn;h++){
                        int x1 = max(yy[k].x1 , yy[h].x1);
                        int x2 = min(yy[k].x2 , yy[h].x2);
                        if ( x1>=x2 ) continue;


                        if ( y1<min(yy[k].y1,yy[h].y1) &&
                             y2>max(yy[k].y1,yy[h].y1) ){
                            if ( x1<min(xx[i].x1,xx[j].x1) &&
                                 x2>max(xx[i].x1,xx[j].x1) )
                                ans++;
                        }
                    }
            }
        printf("%d\n" , ans);

    }

    return 0;
}
