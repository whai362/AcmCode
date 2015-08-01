#include <iostream>
#include <cstdio>
using namespace std;
#define LL __int64
int main(){
	LL a[6];
	for(int i = 0; i < 6; ++i)
		cin>>a[i];
	LL B1 = a[0] + a[1];
	LL B2 = a[1] + a[2];
	LL ans = B1 * B2 * 2;
	ans -= a[1] * a[1] + a[4] * a[4];
	cout << ans << endl;
	return 0;
}

