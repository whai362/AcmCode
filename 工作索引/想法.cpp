给出一串数字，求l和r中x出现了多少次 used

求一段异或和最大 trie used

字典树求最大异或值 used

前后缀匹配，如果匹配设1，否则设0，用kmp，next数组做。参见zoj3274 used

C(n,m) 1e18 used

define x=f(a,b) as x=a|b && a&b=0
so x1=f(a,b),
   x2=f(a,c);
求max(a); used shui

求三个数异或和为0 fwt 质因数少

求l和r之间0，1绝对值之差最小的数，输出最小的

给出一串数字，求l和r中出现次数最多的数，及其次数 区间众数解题报告 - 陈立杰

斯坦纳树
一个无向连通图，n个点，m条边，每条边权为wi，给定k1个点和k2个点，求让k1个点和k2个点连通的权值最小的方案。
限制：
3<=n<=100，0<m<=10000，无自环，无重边，0<wi<=1000，0<k<=17

LIS 求最短 n=1000000 加强对lis的理解  bc16 1002

求有多少个直角三角形 快速傅里叶变换

给出两个矩形，a1,b1,a2,b2，可以1/2切，可以2/3切，求最大相等的面积。

细胞分裂 没次有p的概率分裂，求t秒后数目超过s的概率

给出点P和一条线段L，再给出一个点Q和一个点A，线段L绕P顺时针旋转，点A绕Q顺时针旋转，他们的角速度相等，问他们能不能碰撞。

给出1e5字符串（26个小写字母），求有多少个不同的子序列（不是子串哦，想想改成子串怎么做）。
解法 dp[26];
int tmp=0;
for(i,1,26)
	tmp+=dp[i];
dp[ch]=tmp+1;
int ans=0;
for(i,1,26)
	ans+=dp[i];

有一个正整数序列a长度为n,且 ai+1 > ai ， 定义 d = max(ai+1 - ai)。
问能否去掉k个数（首尾除外）使得d不超过x?
1<=k<=n-2, n <= 10^5

奇怪的图形加边，cf284e

x >= Phi(C), A^x = A ^ (x%Phi(C) + Phi(C)) (mod C)
求
1. x=2^x 
2. x+=a
求交互操作n次后的结果

数的拆分,最大的加数为m dp

cf 279 d 对数字进行奇怪的分解

有n个质量不同的物品，其质量范围为1到n。物品从1到n编号，现在给出m个条件，每个条件为(a，b)，表示物品a比物品b轻。问这n个物品的质量分配有多少种方法。n=100 m=10
拓扑排序种数

找到一个圆，使得给出的点在圆上的数目最大，怎么写 圆周角相等

KD-tree 查询一个矩形内有几个点 有没有比较好的写法

图，数的异或拆分，1的位数比相连的点少。

f(n,k)=sigma((n)k)
21 7
0 1 2 3 4 5 6 1 2 3 4 5 6 0 2 3 4 5 6 0 1

循环矩阵乘法

fancy line：一条直线上只有三个点。
给n个点的坐标，求有多少条fancy line
ax+by+c=0
求a，b，c用hashmap做。

有范围的括号匹配，使他们的长度和最大化（不知道这样对不对）
思路：对(l,r)先排序
先对l,r处理下，处理成奇数，因为偶数不可能。
bool cmp(Dt a,Dt b){
	if(a.r==b.r) return a.l<b.l;
	return a.r>b.r;
}
然后用栈做。
codeforces 508 E

给出n个数，求花费最小的异或和为0

给出1~n，问最大公约数为1的三元组有多少个。
质数，容斥
poj 跳蚤

2 * 3 * 5 * 7 * … * P + 1 是一个素数

给出n个数，m个询问，每次询问[l,r]是否是一个集合
思路：预处理出对于每个位置，他前一个相同的数对的位置 参照bc 29 c
问题二：判断是不是连续的

将1~N*N这N*N个数填入一个N*N的表格中，使得每一行，每一列，每一对角线的和彼此不相等
1 2 7
3 4 8
5 6 9

给出一个深搜序，问有多少颗树(二叉一样)符合这个深搜序
卡特兰数

一条线有n个点，相邻点之间有边，所有两个城市之间(max-min)的和。
思路：单调栈，并查集 参考bc30 c

whai结：就是一个结点的权值，比它所在的whai结的权值都下，求对于每个结点，以它为中心的whai结多大。
思路：并查集 参考bc30 c

给出n个数，求对于每个数求和它互质的数有多少个
莫比乌斯反演 参考hdu 5072

求
(1/a1a2 + 1/a1a3 + ... + 1/a2a3 + ... + 1/a[n-1]a[n])*a1*a2*...*a[n]
先预处理逆元1/a[i]
然后用1...n逆元的和的平方-(1/a1a1+1/a2a2+...+1/a[n]a[n])，然后再除以2，然后再乘上a1*a2*...*a[n]即可

n国王问题
国王能吃他四周的八个棋子，给出n*m的棋盘，问放国王，且他们不互相次有多少种方法。n=10,m=1e5
状态压缩dp 参照bc31 c

给出n,m, 表示长度为m的字符串里只含n种字母, 给出字符串, 再给出每种字母增加和删除的代价c1,c2, 求把这个字符串变成回文串的最小代价。删除字母只能在前后。
线段树，程序写在dp的yy1.cpp里

无序的整数拆分
比如数字n拆成m份(a,b)和(b,a)属于不同情况
ans=C(n-m-1,m-1)

1~n的数，求冒泡排序需要进行m次才能排成从小到大的序列的排列方式有多少种
dp
dp[i][j]=sigma(dp[i-1][0]+...+dp[i-1][j])

给出n个数，求对于每个数，和它互质的数有多少个。莫比乌斯反演，O(nsqrt(n))

给出一个字符串，问对于任意一个位置p，0~p是否是由m段相同的字符串组成的。
