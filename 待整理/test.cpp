/* 决策矩阵求最优值
假设有决策矩阵
        对方 决策1 决策2
我方 决策1    A     B      p
     决策2    C     D     1-p  （A\B\C\D表示对于这个决策组合我方的胜率）
最优期望胜率满足
假设我方执行决策1和决策2 的概率分别为p和1-p
那么，如果这个概率使得无论对方选择何种决策，总的期望胜率是一致，
	则Ap+C(1-p)=Bp+D(1-p)=最优胜率
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
double dp[1010][1010];
int N, M;
double Dp(int N, int M) {
	if (dp[N][M] >= 0) return dp[N][M];
	if (N == 0) return 1.00 / (M + 1);
	if (M == 0) return 1.00;
	//do trick and the opponent believes
	double A = 1.00;
	//do trick and the opponent doesn't belive
	double B = 1.00 - Dp(M, N - 1);
	//guess the opponent's card
	//if incorrect; opponent believes ? C : D
	double C = (double)M / (M + 1) * (1 - Dp(M - 1, N));
	double D = (double)M / (M + 1) * (1 - Dp(M - 1, N)) + 1.00 / (M + 1);
	//A * P + B * (1 - P) = C * P + D * (1 - P)
	//AP - BP - CP + DP = D - B
	double P = (D - B) / (A - B - C + D);
	dp[N][M] = P * A + (1 - P) * B;
	return dp[N][M];
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i = 0; i < 1010; ++ i)
		for (int j = 0; j < 1010; ++ j)
			dp[i][j] = -0x7ffff;
	printf("%.10lf %.10lf\n", Dp(N,M), 1 - Dp(N,M));
	return 0;
}

