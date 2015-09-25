#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e6 + 5;

char str[N];

void gao(char str[]) {
	int len = strlen(str);
	int c_cnt = 0;
	int flag = 1;
	for(int i = 0; i < len; ++i) {
		if(str[i] == 'c') {
			++c_cnt;
		}
		if(str[i] != 'c' && str[i] != 'f') {
			flag = 0;
		}
	}
	if(flag == 0) {
		puts("-1");
	}
	else if(c_cnt == 0) {
		int ans = len / 2;
		if(len % 2) ++ans;
		printf("%d\n", ans);
	} else {
		for(int i = 0; i < len; ++i) {
			if(str[i] == 'c') {
				int p = (i + 1) % len;
				int sz = 0;
				while(str[p] != 'c') {
					p = (p + 1) % len;
					++sz;
				}
				//cout<<sz<<endl;
				if(sz < 2) {
					flag = 0;
					break;
				}
			}
		}
		if(flag == 0) {
			puts("-1");
		} else {
			printf("%d\n", c_cnt);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		scanf("%s", str);
		printf("Case #%d: ", ++cas);
		gao(str);
	}
	return 0;
}
