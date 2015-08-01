#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
using namespace std;
#define LL __int64
#define P pair< int, LL >
#define X first
#define Y second
const LL INF = 1000000000000LL;
queue< P > que;
//set< P > //_set;
bool ok(LL L, LL R, LL LIM){
    if((L == 0 || R - L + 1 <= L)) return true;
    return false;
}
void gao(LL L, LL R) {
    ////_set.clear();
	if(L == R){
		printf("%I64d\n", R);
		return ;
	}
    que.push(P(L, R));
    LL ans = 2*R;
    while(!que.empty()) {
        P now = que.front();
        que.pop();

        if(now.X == 0){
			ans = min(ans, now.Y);
			continue;
		}
        LL L = now.X - (now.Y - now.X + 1);
        LL R = now.Y;
        if(ok(L, R, ans)){
            que.push(P(L, R));
            //_set.insert(P(L, R));
        }
        --L;
        if(ok(L, R, ans)){
            que.push(P(L, R));
            //_set.insert(P(L, R));
        }

        L = now.X;
        R = now.Y + now.Y - now.X;
        if(ok(L, R, ans)){
            que.push(P(L, R));
            //_set.insert(P(L, R));
        }
        ++R;
        if(ok(L, R, ans)){
            que.push(P(L, R));
            //_set.insert(P(L, R));
        }
    }
    if(ans == 2*R) puts("-1");
    else printf("%I64d\n", ans);
}
int main() {
    LL L, R;
    while(scanf("%I64d%I64d", &L, &R) != EOF){
        gao(L, R);
    }
    return 0;
}
