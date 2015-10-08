Bell数
1. 定义：
第n个Bell数表示集合{1,2,3,...,n}的划分方案数，即：B[0] = 1;

2. 其指数生成函数：
sigma(n=0~inf,B[n]/n! * x^n) = e^(e^x - 1)

3. 性质：
(1) Bell数与第二类Stiring数的关系：
B[n] = sigma(k=1~n,S(n,k)) , S()表示S第二类tiring数
第二类Stirling数的意义是：S(n,k)表示将n个物体划分成k个非空的不可辨别的（可以理解为盒子没有编号）集合的方法数。

(2) Bell三角形(构建方法类似于杨辉三角形)
Bell三角形的构造方法：
第一行第一个元素是1，即a[1][1] = 1
对于n>1，第n行第一项等于第n-1行最后一项，即a[n][1] = a[n-1][n-1];
对于m,n>1，第n行第m项等于它左边和左上方的两个数之和，即a[n][m] = a[n][m-1] + a[n-1][m-1];

前几项Bell三角形如下：
1
1	2
2	3	5
5	7	10	15
15	20	27	37	52
52	67	87	114	151	203

(3) Bell数的同余性质：
(B[n] + B[n+1]) % p = B[p+n] % p , 其中p为任意质数
(mB[n] + B[n+1]) % p = B[p^m + n] % p , 其中p为任意质数

(4) Bell数模素数p的周期为：
N[p] = (p^p - 1) / (p - 1)

4. Bell数预处理
LL T[55], B[55];
void get_bell(int n, int mod) {
	B[0] = 1;
	B[1] = 1;
	T[0] = 1;
	for (int i = 2; i <= n; ++i) {
		T[i - 1] = B[i - 1];
		for (int j = i - 2; j >= 0; --j)
			T[j] = (T[j] + T[j + 1]) % mod;
		B[i] = T[0];
	}
}

5. 利用同余性质求大Bell数的模值(要预处理到模)
//求B[n]%mod
//要先预处理前50项Bell数，当然可以更多
//vis每次调用前都要清空
map<int, LL> vis;
LL bell_mod(int n, int mod) {
	LL ret = vis[n];
	if (ret) return ret;
	if (n <= 50) return B[n];	//改
	LL k = 0;
	LL P = 1;
	while (P < n) {
		P = P * mod;
		++k;
	}
	P /= mod;
	--k;
	return vis[n] = (k * bell_mod(n - P, mod) + bell_mod(n - P + 1, mod)) % mod;
}

