#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define LL long long

const int N = 205;
const int MOD = 1000000007;

int type[N], t_tot;
int op[N], o_tot;

char str[1000000];

bool is_dig(char c) {
	if(c >= '0' && c <= '9') {
		return true;
	}
	return false;
}

bool is_let(char c) {
	if(!is_dig(c) && c != '*' && c != '.' && c != '^' && c != '!')
		return true;
	return false;
}

LL dp[N][N][2];

void init() {
	t_tot = o_tot = 1;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}
}
void deal(int l, int r) {
	//cout<<l<<' '<<r<<endl;
	if(dp[l][r][0] != -1) return ;
	dp[l][r][0] = dp[l][r][1] = 0;
	if(l > r) {
		//cout<<'?'<<l<<' '<<r<<endl;
		if(type[l] == 0) {
			dp[l][r][0] = 1;
		} else {
			dp[l][r][1] = 1;
		}
		return ;
	}
	for(int i = l; i <= r; ++i) {
		deal(l, i - 1);
		deal(i + 1, r);
		//cout<<'!'<<dp[l][i - 1][0]<<' '<<dp[l][i - 1][1]<<endl;
		//cout<<'!'<<dp[i + 1][r][0]<<' '<<dp[i + 1][r][1]<<endl;
		if(op[i] == 0) {
			dp[l][r][0] = (dp[l][r][0] + dp[l][i - 1][0] * dp[i +
				1][r][0]) % MOD;
			dp[l][r][1] = (dp[l][r][1] + dp[l][i - 1][0] * dp[i +
				1][r][1]) % MOD;
			dp[l][r][1] = (dp[l][r][1] + dp[l][i - 1][1] * dp[i +
				1][r][0]) % MOD;
		} else if(op[i] == 1) {
			dp[l][r][0] = (dp[l][r][0] + dp[l][i - 1][1] * dp[i +
				1][r][1]) % MOD;
		} else if(op[i] == 2) {
			dp[l][r][1] = (dp[l][r][1] + dp[l][i - 1][1] * dp[i +
				1][r][1]) % MOD;
		} else {
			dp[l][r][0] = (dp[l][r][0] + dp[l][i - 1][1] * dp[i +
				1][r][1]) % MOD;
			dp[l][r][1] = (dp[l][r][1] + dp[l][i - 1][0] * dp[i +
				1][r][1]) % MOD;
			dp[l][r][1] = (dp[l][r][1] + dp[l][i - 1][1] * dp[i +
				1][r][0]) % MOD;
			dp[l][r][1] = (dp[l][r][1] + dp[l][i - 1][0] * dp[i +
				1][r][0]) % MOD;
		}
	}
}

void gao(char str[]) {
	init();
	int len = strlen(str);
	for(int i = 0; i < len; ++i) {
		if(is_dig(str[i])) {
			type[t_tot++] = 0;
			while(is_dig(str[i])) {
				++i;
			}
			--i;
		} else if(is_let(str[i])) {
			type[t_tot++] = 1;
			while(is_let(str[i])) {
				++i;
			}
			--i;

		} else if(str[i] == '*') {
			op[o_tot++] = 0;
		} else if(str[i] == '.') {
			op[o_tot++] = 1;
		} else if(str[i] == '^') {
			op[o_tot++] = 2;
		} else if(str[i] == '!') {
			op[o_tot++] = 3;
		}
	}
	//for(int i = 1; i < t_tot; ++i) {
	//	cout<<type[i]<<' ';
	//}
	//cout<<endl;
	//for(int i = 1; i < o_tot; ++i) {
	//	cout<<op[i]<<' ';
	//}
	//cout<<endl;
	if(o_tot > 0) {
		if(o_tot == t_tot - 1) {
			deal(1, o_tot - 1);
			cout<<(dp[1][o_tot - 1][0] + dp[1][o_tot - 1][1]) % MOD<<endl;
		} else {
			cout<<0<<endl;
		}
	} else {
		cout<<1<<endl;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", str);
		gao(str);
	};
	return 0;
}
