#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
const int N = 6;
LL a[N];
LL ans[10];
LL _abs(LL x){
	if(x < 0) return -x;
	return x;
}
void gao(){
	if(a[0] > 0) a[1] -= a[0], a[0] = 0;
	if(a[1] < 0) a[0] -= a[1], a[1] = 0;
	if(a[2] > 0) a[3] -= a[2], a[2] = 0;
	if(a[3] < 0) a[2] -= a[3], a[3] = 0;
	if(a[4] > 0) a[5] -= a[4], a[4] = 0;
	if(a[5] < 0) a[4] -= a[5], a[5] = 0;

	ans[0] = a[1] * a[3] * a[5];
	ans[1] = a[0] * a[3] * a[5];
	ans[2] = a[0] * a[2] * a[5];
	ans[3] = a[1] * a[2] * a[5];
	ans[4] = a[1] * a[3] * a[4];
	ans[5] = a[0] * a[3] * a[4];
	ans[6] = a[0] * a[2] * a[4];
	ans[7] = a[1] * a[2] * a[4];

	cout<<_abs(ans[0]);
	for(int i = 1; i < 8; ++i){
		cout<<' '<<_abs(ans[i]);
	}
	cout<<endl;
}
int main() {
	int T;
	cin>>T;
	while(T--){
		for(int i = 0; i < 6; ++i){
			cin>>a[i];
		}
		gao();
	}
	
	return 0;
}
