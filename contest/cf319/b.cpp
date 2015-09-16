#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define PB push_back

const int N = 1e5 + 5;

int a[N];

bool used[N];

vector<int> cir[N];
int tot = 0;

void get_cir(int S, int id) {
	int p = S;
	while(used[p] == 0) {
		cir[id].PB(p);
		used[p] = 1;
		p = a[p];
	}
}

void gao(int n) {
	for(int i = 1; i <= n; ++i) {
		if(used[i] == 0) {
			get_cir(i, tot);
			++tot;
		}
	}
	//for(int i = 0; i < tot; ++i) {
	//	cout<<cir[i].size()<<endl;
	//	for(int j = 0; j < cir[i].size(); ++j) {
	//		cout<<cir[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
	bool have1 = 0;
	int rt = 0;
	for(int i = 0; i < tot; ++i) {
		if(cir[i].size() == 1) {
			have1 = 1;
			rt = cir[i][0];
			break;
		}
	}
	if(have1) {
		puts("YES");
		int u = rt;
		for(int i = 0; i < tot; ++i) {
			for(int j = 0; j < cir[i].size(); ++j) {
				int v = cir[i][j];
				if(u == v) continue;
				cout<<u<<' '<<v<<endl;
			}
		}
	} else {
		int u, v;
		bool have2 = 0;
		bool all_even = 1;
		for(int i = 0; i < tot; ++i) {
			if(cir[i].size() == 2) {
				have2 = 1;
				u = cir[i][0];
				v = cir[i][1];
			}
			if(cir[i].size() % 2) {
				all_even = 0;
			}
		}
		if(have2 && all_even) {
			puts("YES");
			cout<<u<<' '<<v<<endl;
			for(int i = 0; i < tot; ++i) {
				for(int j = 0; j < cir[i].size(); ++j) {
					int w = cir[i][j];
					if(w == u || w == v) continue;
					if(j % 2 == 0) {
						cout<<u<<' '<<w<<endl;
					} else {
						cout<<v<<' '<<w<<endl;
					}
				}
			}
		} else {
			puts("NO");
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	gao(n);
	return 0;
}
