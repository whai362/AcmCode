#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define LL __int64
#define PB push_back
const int N = 1e5 + 5;

vector<int> ans[15];

bool vis[N];

void init(int n, int m) {
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < m; ++i)
		ans[i].clear();
}

int main() {
	int T;
	int n, m;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		init(n, m);
		LL sum = (1 + n) * n / 2;
		//cout<<sum<<endl;
		if(sum % m != 0) {
			puts("NO");
			continue;
		} else {
			int cnt = 0;
			LL avg = sum / m;
			for(int i = 0; i < m; ++i) {
				LL tmp = avg;
				for(int j = n; j >= 1; --j) {
					if(vis[j] == 0 && j <= tmp) {
						ans[i].PB(j);
						tmp -= j;
						vis[j] = 1;
						++cnt;
						if(tmp == 0) break;
					}
				}
			}
			//cout<<cnt<<endl;
			//if(cnt != n) puts("NO");
			//else {
				puts("YES");
				for(int i = 0; i < m; ++i) {
					printf("%d", ans[i].size());
					for(int j = 0; j < ans[i].size(); ++j){
						printf(" %d", ans[i][j]);
					}
					puts("");
				}
			//}
		}
	}
	return 0;
}
