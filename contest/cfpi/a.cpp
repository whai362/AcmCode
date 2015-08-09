#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL __int64
const int N = 1e5 + 5;
LL a[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%I64d", &a[i]);
	sort(a, a+n);
	for(int i = 0; i < n; ++i) {
		//cout<<a[i]<<endl;
		if(i == 0) {
			cout<<a[i + 1] - a[i]<<' '<<a[n - 1] - a[i]<<endl;
		} else if(i == n - 1) {
			cout<<a[i] - a[i - 1]<<' '<<a[i] - a[0]<<endl;
		} else {
			cout<<min(a[i + 1] - a[i], a[i] - a[i - 1])<<' ';
			cout<<max(a[i] - a[0], a[n - 1] - a[i])<<endl;
		}
	}
	return 0;
}
