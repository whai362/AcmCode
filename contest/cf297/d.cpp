/*codeforces 525 D Arthur and Walls
  题意：
  给出一个n*m的表格，里面有'*'和'.'，求把最少的'*'移除掉，使得'.'所在的连通块是矩形。
  限制：
  1 <= n,m <= 2000
  思路：
  2*2地考虑，如果2*2的格子里只有一个'*'，说明这个'*'要去掉，其他情况都不用去掉。然后去掉这个'*'后，又会对其他四个格子有影响。
  复杂度好难估计。
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005;
char str[N][N];
int n,m;
void gao(int x,int y){
	if(x==n-1 || y==m-1 || x<0 || y<0) return ;
	int tx,ty,s=0;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			if(str[x+i][y+j]=='*'){
				++s;
				tx=x+i;
				ty=y+j;
			}
	if(s==1){
		str[tx][ty]='.';
		for(int i=-1;i<1;++i)
			for(int j=-1;j<1;++j){
				gao(tx+i,ty+j);
			}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%s",str[i]);
	for(int i=0;i<n-1;++i)
		for(int j=0;j<m-1;++j){
			gao(i,j);
		}
	for(int i=0;i<n;++i)
		puts(str[i]);
	return 0;
}
