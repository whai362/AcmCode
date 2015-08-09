#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 + 5;
int in[N];
int A[N], B[N];
int main() {
	int n;
	int ans = 0;
	scanf("%d", &n);
	char op[5];
	int id;
	for(int i = 1; i <= n; ++i) {
		scanf("%s%d", op, &id);
		A[i] = A[i - 1];
		B[i] = B[i - 1];
		if(op[0] == '+') {
			in[id] = 1;
			++A[i];
			//cout<<A[i]<<'!'<<endl;
		} else {
			if(in[id] == 0) {
				--B[i];
			} else {
				in[id] = 0;
				--A[i];
			}
		}
		//cout<<A[i]<<' ';
	}
	//cout<<endl;
	int tt = -B[n];
	//for(int i = 1; i <= n; ++i)
	//	cout<<A[i]<<' ';
	//cout<<endl;
	//for(int i = 1; i <= n; ++i)
	//	cout<<B[i]<<' ';
	//cout<<endl;
	for(int i = 0; i <= n; ++i) {
		ans = max(ans, A[i] + tt + B[i]);
	}
	cout<<ans<<endl;
	return 0;
}
