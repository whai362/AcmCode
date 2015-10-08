#include <iostream>
#include <cstdio>
using namespace std;

int w[5], h[5];
int a[5], b[5], t[5];
const int N = 1005;

char ans[N][N];

int main() {
	int maxx = 0;
	for(int i = 0; i < 3; ++i) {
		cin>>w[i]>>h[i];
		if(w[i] < h[i]) swap(w[i], h[i]);
		maxx = max(maxx, w[i]);
	}
	int sel = -1;
	for(int i = 0; i < 3; ++i) {
		if(w[i] == maxx) {
			sel = i;
			break;
		}
	}
	int tot = 0;
	for(int i = 0; i < 3; ++i) {
		if(i == sel) continue;
		a[tot] = w[i];
		b[tot] = h[i];
		t[tot++] = i;
	}
	int flag = -1;
	if(a[0] == a[1] && a[0] == w[sel] && b[0] + b[1] == w[sel] - h[sel]) {
		flag = 0;
	} else {
		int ok1 = 0, ok2 = 0;
		if(a[0] == w[sel] - h[sel]) {
			ok1 = 1;
		} else if(b[0] == w[sel] - h[sel]) {
			ok1 = 1;
			swap(a[0], b[0]);
		}

		if(a[1] == w[sel] - h[sel]) {
			ok2 = 1;
		} else if(b[1] == w[sel] - h[sel]) {
			ok2 = 1;
			swap(a[1], b[1]);
		}

		if(ok1 && ok2 && b[0] + b[1] == w[sel]) {
			flag = 1;
		}
	}


	if(flag == -1) puts("-1");
	else {
		cout<<w[sel]<<endl;
		for(int i = 0; i < h[sel]; ++i) {
			for(int j = 0; j < w[sel]; ++j) {
				ans[i][j] = 'A' + sel;
			}
		}
		if(flag == 0) {
			for(int i = h[sel]; i < h[sel] + b[0]; ++i) {
				for(int j = 0; j < a[0]; ++j) {
					ans[i][j] = 'A' + t[0];
				}
			}
			for(int i = h[sel] + b[0]; i < h[sel] + b[0] + b[1]; ++i) {
				for(int j = 0; j < a[1]; ++j) {
					ans[i][j] = 'A' + t[1];
				}
			}
		} else {
			for(int i = 0; i < b[0]; ++i) {
				for(int j = h[sel]; j < h[sel] + a[0]; ++j) {
					ans[j][i] = t[0] + 'A';
				}
			}
			for(int i = b[0]; i < b[0] + b[1]; ++i) {
				for(int j = h[sel]; j < h[sel] + a[1]; ++j) {
					ans[j][i] = t[1] + 'A';
				}
			}
		}
		for(int i = 0; i < w[sel]; ++i) {
			puts(ans[i]);
		}
	}
	return 0;
}
