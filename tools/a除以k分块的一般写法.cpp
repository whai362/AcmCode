//区间[i, ls]的floor(a/k) == x，所以下面是按照x不同进行分块操作
int sum[N];
LL ans = 0;
for (int i = 1, ls = 0; i <= min(a, b); i = ls + 1) {	//分块
	ls = min(a / (a / i), b / (b / i));
	ans += ((LL)sum[ls] - sum[i - 1]) * (a / i) * (b / i);
}
