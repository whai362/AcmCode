#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 + 5;
int cnt[N];
int s[N][8];

void deal(int x) {
	int X = x;
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			++cnt[X];
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) ++cnt[X];
}

void predo() {
	cnt[0] = cnt[1] = 0;
	for(int i = 2; i < N; ++i){
		deal(i);
	}
	//cout<<"!"<<endl;
	for(int i = 2; i < N; ++i){
		for(int j = 0; j < 7; ++j)
			s[i][j] = s[i - 1][j];
		for(int j = 1; j <= cnt[i]; ++j){
			if(cnt[i] % j == 0) ++s[i][j - 1];
		}
	}
	//cout<<"?"<<endl;
}

void gao(int l, int r){
	int ans = 0;
	for(int i = 0; i < 7; ++i){
		if(s[r][i] - s[l - 1][i] > 1) ans = i + 1;
	}
	printf("%d\n", ans);
}

int main() {
	int n;
	predo();
	while(scanf("%d", &n) != EOF) {
		int l, r;
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &l, &r);
			gao(l, r);
		}
	}
	return 0;
}
