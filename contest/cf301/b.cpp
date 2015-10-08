#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1005;

int a[N];

int main() {
	int n, k, p, x, y;
	cin>>n>>k>>p>>x>>y;
	int sum = 0;
	int cnt = 0;
	for(int i = 0; i < k; ++i) {
		cin>>a[i];
		sum += a[i];
		if(a[i] >= y) {
			++cnt;
		}
	}
	if(cnt > n / 2) {
		sum += n - k;
		if(sum > x) {
			puts("-1");
		} else {
			for(int i = 0; i < n - k; ++i) {
				cout<<1<<' ';
			}
			cout<<endl;
		}
	} else {
		int nd = n / 2 + 1 - cnt;
		sum += nd * y;
		if(k + nd > n) {
			puts("-1");
		} else {
			sum += n - k - nd;
			if(sum > x) {
				puts("-1");
			} else {
				for(int i = 0; i < nd; ++i) {
					cout<<y<<' ';
				}
				for(int i = 0; i < n - k - nd; ++i) {
					cout<<1<<' ';
				}
				cout<<endl;
			}
		}

	}
	return 0;
}
