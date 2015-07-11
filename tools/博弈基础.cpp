/*一. 基本概念：
  1. 组合游戏：
  (1) 有两个玩家;
  (2) 游戏的操作状态是一个有限的集合(比如：限定大小的棋盘);
  (3) 游戏双方轮流操作;
  (4) 双方的每次操作必须符合游戏规定;
  (5) 当一方不能将游戏继续进行的时候，游戏结束，同时，对方为获胜方;
  (6) 无论如何操作，游戏总能在有限次操作后结束;

  2. 必败点(P点)：前一个选手(Previous player)将取胜的位置称为必败点。

  3. 必胜点(N点)：下一个选手(Next player)将取胜的位置称为必胜点。 

  二. 必败/必胜点属性：
  1. 所有终结点是必败点(P点);
  2. 从任何必胜点(N点)操作，至少有一种方法可以进入必败点(P点);
  3. 无论如何操作，从必败点(P点)都只能进入必胜点(N点)。

  三. 一般解题策略：
  1. 将所有终结位置标记为必败点(P点);
  2. 将所有一步操作能进入必败点(P点)的位置标记为必胜点(N点);
  3. 如果从某个点开始的所有一步操作都只能进入必胜点(N点)，则将该点标记为必败点(P点);
  4. 如果在步骤3未能找到新的必败(P点)，则算法终止;否则，返回到步骤2。
 */

/*hdu 1846
  题意：
  1. 本游戏是一个二人游戏;
  2. 有一堆石子一共有n个；
  3. 两人轮流进行;
  4. 每走一步可以取走1…m个石子；
  5. 最先取光石子的一方为胜；
  求谁先赢。
  限制；
  1 <= n, m <= 1000
  思路：
  博弈的基本概念。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005;
bool dp[N];
int n,m;
bool win(int x){
	for(int i=1;i<=m;++i){
		int tmpx=x-i;
		if(tmpx>=0 && dp[tmpx]==0) return true;
	}
	return false;
}
bool fail(int x){
	for(int i=1;i<=m;++i){
		int tmpx=x-i;
		if(tmpx<0) continue;
		if(dp[tmpx]!=1) return false;
	}
	return true;
}
void gao(int n,int m){
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;++i){
		if(win(i)) dp[i]=1;
		else if(fail(i)) dp[i]=0;
	}
	if(dp[n]) puts("first");
	else puts("second");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		gao(n,m);
	}
	return 0;
}
