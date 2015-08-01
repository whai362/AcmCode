#include <iostream>
#include <cstdio>
using namespace std;
#define LL __int64
bool ok(LL L, LL R, LL l, LL r){
	if(l == L && r == R){
		return true;
	}
	int mid = (l + r) >> 1;
	if(R <= mid) return ok(L, R, l, mid);
	else if(L > mid) return ok(L, R, mid+1, r);
	else return false;
}

int main() {
	LL L, R;
	while(scanf("%I64d%I64d", &L, &R) != EOF){
		LL ans = -1;
		for(LL i = R; i <= R + 10000; ++i){
			if(ok(L, R, 0, i)){
				ans = i;
				break;
			}
		}
		printf("%I64d\n", ans);
	}
}
