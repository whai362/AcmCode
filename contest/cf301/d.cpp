#include <iostream>
#include <cstdio>
using namespace std;

const int N = 105;

double dp[N][N][N];
double sqr(double x) {
	return x * x;
}

bool ok(int x, int y, int z) {
	if(x == 0 && y == 0 && z) return false;
	if(x == 0 && y && z == 0) return false;
	if(x && y == 0 && z == 0) return false;
	return true;
}

int main() {
	int r, s, p;
	cin>>r>>s>>p;
	dp[r][s][p] = 1;

	for(int i = r; i >= 0; --i) {
		for(int j = s; j >= 0; --j) {
			for(int k = p; k >= 0; --k) {
				if(i == 0 && j == 0 && k == 0) continue;
				dp[i][j][k] += (dp[i + 1][j][k] * (k * (i + 1)) + dp[i][j + 1][k] * (i * (j + 1)) + dp[i][j][k + 1] * (j * (k + 1))) / ((i + j + k) * (i + j + k + 1) / 2);
				if(ok(i, j, k)) dp[i][j][k] /= (1.0 - (double)(i * (i - 1) + j * (j - 1) + k * (k - 1)) / ((i + j + k) * (i + j + k - 1)));
				//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
			}
		}
	}

	double ans1 = 0, ans2 = 0, ans3 = 0;
	for(int i = 1; i <= max(r, max(s, p)); ++i) {
		ans1 += dp[i][0][0];
		ans2 += dp[0][i][0];
		ans3 += dp[0][0][i];
	}


	printf("%.10f %.10f %.10f\n", ans1, ans2, ans3);
	return 0;
}
