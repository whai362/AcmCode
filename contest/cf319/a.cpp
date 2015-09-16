#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define LL __int64
const int N = 1005;

bool is_pri[N];
int pri[N], tot;
void get_pri(int n){
	tot = 0;
	memset(is_pri, 1, sizeof(bool) * (n + 1));
	is_pri[0] = is_pri[1] = 0;
	for(int i = 2; i <= n; ++i)
		if(is_pri[i]){
			if(n / i < i) break;
			for(int j = i * i; j <= n; j += i) is_pri[j] = false;
		}
	for(int i = 2; i <= n; ++i) if(is_pri[i]) pri[tot++] = i;
}

void gao(int x) {
	get_pri(1004);
	vector<LL> ans;
	for(int i = 1; i <= x; ++i) {
		if(is_pri[i]) {
			LL tmp = i;
			while(tmp <= x) {
				ans.push_back(tmp);
				tmp *= i;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i = 0; i < ans.size(); ++i) {
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}

int main() {
	int n;
	cin>>n;
	gao(n);
	return 0;
}
