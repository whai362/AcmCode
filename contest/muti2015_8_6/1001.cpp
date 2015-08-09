#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL __int64
const int N = 1e5 + 5;
int a[N];
int used[N];

int tmp_a[N];
bool deal(int n, int type) {
	for(int i = 0; i < n; ++i) {
		tmp_a[i] = a[i];
	}
	memset(used, 0, sizeof(used));
	used[0] = type;
	if(type == 1) {
		--tmp_a[0];
		++tmp_a[1];
	} else if(type == 2) {
		++tmp_a[0];
		--tmp_a[1];
	}
	for(int i = 1; i < n; ++i) {
		int nxt = (i + 1) % n;
		if(tmp_a[i] == 1) {
			--tmp_a[i];
			++tmp_a[nxt];
			used[i] = 1;
		} else if(tmp_a[i] == -1) {
			++tmp_a[i];
			--tmp_a[nxt];
			used[i] = 2;
		} else if(tmp_a[i] == 0) {
			used[i] = 3;
		} else return false;
	}
	return true;
}

bool all_same(int n) {
	for(int i = 1; i < n; ++i)
		if(a[i] != a[i - 1]) return false;
	return true;
}

void gao(int n) {
	if(all_same(n)) {
		puts("YES");
		puts("0");
		return ;
	}
	if(n == 1) {
		puts("YES");
		puts("0");
		return ;
	} else if(n == 2) {
		if(a[0] + 1 == a[1]) {
			puts("YES");
			puts("1");
			puts("2 1");
		} else if(a[0] - 1 == a[1]) {
			puts("YES");
			puts("1");
			puts("1 2");
		} else if(a[0] == a[1]) {
			puts("YES");
			puts("0");
		} else puts("NO");
		return ;
	}
	LL sum = 0;
	for(int i = 0; i < n; ++i)
		sum += (LL)a[i];
	if(sum % n) {
		puts("NO");
		return ;
	} else {
		LL avg = sum / n;
		for(int i = 0; i < n; ++i)
			a[i] -= avg;
	}
	
	int flag = 0;
	for(int i = 1; i <= 3; ++i) {
		if(deal(n, i)){
			flag = 1;
			break;
		}
	}
	if(!flag){
		puts("NO");
		return ;
	}
	puts("YES");
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(used[i] == 1 || used[i] == 2) ++cnt;
	}
	printf("%d\n", cnt);
	for(int i = 0; i < n; ++i) {
		if(used[i] == 1) printf("%d %d\n", i + 1, (i + 1) % n + 1);
		else if(used[i] == 2) printf("%d %d\n", (i + 1) % n + 1, i + 1);
	}
}

int main() {
	int T;
	int n;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		gao(n);
	}
	return 0;
}
