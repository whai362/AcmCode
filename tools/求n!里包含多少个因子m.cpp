//求n!里包含多少个因子m
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = n / m; i > 0; i /= m) cnt += i;
	cout << cnt << endl;
	return 0;
}
