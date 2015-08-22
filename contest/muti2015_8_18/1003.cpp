#include <iostream>
#include <cstdio>
using namespace std;
const int N = 105;
int a[N];
int c[N];

int mu[N];
//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}


int main() {
	getMu();
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i) {
		a[i] = n / i;
		//cout<<a[i]<<' ';
		--a[i];
		cout<<a[i]<<' ';
	}
	cout<<endl;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		c[i] = 0;
		for(int j = 1; i * j <= n; ++j) {
			c[i] += mu[j] * a[i * j];
		}
		ans += c[i] * i;
		//cout<<i<<":"<<c[i]<<' ';
	}
	cout<<endl;
	cout<<ans<<endl;
}
