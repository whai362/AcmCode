#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1005;
char str1[N];
char str2[N];

void gao(int n) {
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int a = str1[i] - 'a', b = str2[i] - 'a';
		if(a < b) swap(a, b);
		int tmp1 = b + 10 - a;
		int tmp2 = a - b;
		//cout<<min(tmp1,tmp2)<<endl;
		ans += min(tmp1, tmp2);
	}
	cout<<ans<<endl;
}

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", str1);
	scanf("%s", str2);
	gao(n);
	return 0;
}
