#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long

LL get_op(LL n) {
	for(int i = 0; i < 64; ++i) {
		if((1LL << i) > n) {
			LL tmp = (1LL << (i - 1));
			if(n == tmp) return 0;
			else return tmp - (n - tmp);
		}
	}
}

void gao(LL n) {
	int flag = 0;
	while(n > 1) {
		n = get_op(n);
		//cout<<n<<endl;
		if(n == 0) break;
		flag ^= 1;
	}
	printf("%d\n", flag);
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		LL n;
		cin>>n;
		printf("Case #%d: ", ++cas);
		gao(n);
	}
	return 0;
}
