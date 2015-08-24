#include <iostream>
#include <cstdio>
using namespace std;

#define LL __int64

LL deal(LL a, LL b, LL c, LL r) {
	if(a < b + c) return 0;
	LL tmp = min(r, a - (b + c));
	return (tmp + 1) * (tmp + 2) / 2;
}

void gao(LL a, LL b, LL c, LL l) {
	LL ans = (l + 1) * (l + 2) * (l + 3) / 6;

	for(int i = 0; i <= l; ++i) {
		ans -= deal(a + i, b, c, l - i);
		ans -= deal(b + i, a, c, l - i);
		ans -= deal(c + i, a, b, l - i);
	}

	cout<<ans<<endl;
}

int main() {
	LL a, b, c, l;
	cin >> a >> b >> c >> l;
	gao(a, b, c, l);
	return 0;
}
