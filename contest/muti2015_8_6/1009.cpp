#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define LL __int64
#define P pair<LL, int>
#define PP pair<P, LL>
#define MP make_pair
#define X first
#define Y second

const int N = 2 * 1e5 + 5;

int L[N], R[N];
LL C[N];

LL ans[N];

priority_queue< PP, vector<PP>, greater<PP> > que;

int fa[N];
void init_bcj(int n) {
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
}
int get_fa(int x) {
	if(x != fa[x]) return fa[x] = get_fa(fa[x]);
	return x;
}

void deal(int pos, int left, int right, LL cost) {
	//cout<<"fa:"<<endl;
	//for(int i = 1; i <= 5; ++i) {
	//	cout<<fa[i]<<' ';
	//}
	//cout<<endl;
	
	for(int i = left; i <= right; ++i) {
		int r = i;
		//cout<<"r: "<<r<<endl;
		while(r <= right && ans[r] != -1){
			r = get_fa(r);
			fa[r] = max(r, right);
			++r;
		}
		//cout<<"r: "<<r<<endl;
		while(r <= right && ans[r] == -1) {
			//cout<<"push: "<<r<<endl;
			que.push(MP(MP(C[r] + cost + C[pos], r), cost + C[pos]));
			ans[r] = cost + C[pos];
			fa[r] = max(r, right);
			++r;
		}
		//cout<<"r: "<<r<<endl;
		i = r - 1;
	}
}

void gao(int n) {
	int left = 1 + L[1];
	int right = min(n, 1 + R[1]);
	for(int i = 1; i <= n; ++i)
		ans[i] = -1;
	ans[1] = 0;
	for(int i = left; i <= right; ++i) {
		if(ans[i] != -1) continue;
		que.push(MP(MP(C[i] + C[1], i), C[1]));
		ans[i] = C[1];
		fa[i] = right;
	}

	while(!que.empty()) {
		PP now = que.top(); que.pop();
		int pos = now.X.Y;
		left = pos + L[pos];
		right = min(n, pos + R[pos]);
		
		//cout<<"pop: "<<pos<<endl;
		//cout<<"l r: "<<left<<' '<<right<<endl;
		
		deal(pos, left, right, now.Y);

		left = max(1, pos - R[pos]);
		right = pos - L[pos];
		
		//cout<<"l r: "<<left<<' '<<right<<endl;
		
		deal(pos, left, right, now.Y);
	}
	for(int i = 1; i <= n; ++i) {
		printf("%I64d%c", ans[i], i == n ? '\n' : ' ');
	}
}

int main() {
	int T;
	int n;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		init_bcj(n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &L[i]);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &R[i]);
		for(int i = 1; i <= n; ++i)
			scanf("%I64d", &C[i]);

		gao(n);
	}
	return 0;
}
