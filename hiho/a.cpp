#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct Dt{
	string x, op;
	int a;
}a[105];

bool ok(int v, int i) {
	if(a[i].op == "<") return v < a[i].a;
	else if(a[i].op == "<=") return v <= a[i].a;
	else if(a[i].op == "=") return v == a[i].a;
	else if(a[i].op == ">") return v > a[i].a;
	else if(a[i].op == ">=") return v >= a[i].a;
	else return false;
}

void gao(int n) {
	int ans = 0;
	for(int i = -2; i <= 3000; ++i) {
		int cnt = 0;
		for(int j = 0; j < n; ++j) {
			if(ok(i, j)) ++cnt;
		}
		ans = max(ans, cnt);
	}
	cout<<ans<<endl;
}

int main() {
	int n;
	while(cin>>n) {
		for(int i = 0; i < n; ++i) {
			cin>>a[i].x>>a[i].op>>a[i].a;
			a[i].a *= 2;
		}
		gao(n);
	}
}
