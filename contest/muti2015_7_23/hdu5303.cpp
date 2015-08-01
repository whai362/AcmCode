#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define LL __int64
const int N = 1e5+5;
#define PB push_back
vector<int> A, B;
LL sum_A[N], sum_B[N];
void gao(int L, int K) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	K = min(K, (int)(A.size() + B.size()));

	sum_A[0] = sum_B[0] = 0;
	for(int i = 1; i <= A.size(); ++i) {
		if(i <= K) sum_A[i] = A[i - 1];
		else sum_A[i] = sum_A[i - K] + A[i - 1];
	}
	for(int i = 1; i <= B.size(); ++i) {
		if(i <= K) sum_B[i] = B[i - 1];
		else sum_B[i] = sum_B[i - K] + B[i - 1];
	}
	LL ans = (sum_A[A.size()] + sum_B[B.size()]) * 2;
	for(int i = 0; i <= A.size() && i <= K; ++i) {
		int lef = A.size() - i, rig = max(0, (int)B.size() - (K - i));
		ans = min(ans, L + (sum_A[lef] + sum_B[rig]) * 2);
	}
	cout<<ans<<endl;
}
void init() {
	A.clear();
	B.clear();
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		//cout<<T<<endl;
		int n, L, K;
		scanf("%d%d%d", &L, &n, &K);
		init();
		int x, a;
		int half = L / 2;
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &x, &a);
			if(x <= half)
				for(int j = 0; j < a; ++j)
					A.PB(x);
			else
				for(int j = 0; j < a; ++j)
					B.PB(L - x);
		}
		//cout<<"!"<<endl;
		gao(L, K);
	}
	return 0;
}
