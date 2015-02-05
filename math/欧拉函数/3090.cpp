/*poj 3090
  题目：
  给出一个n*n的点阵，求从(0,0)出发斜率不相等的直线有多少条。
  限制：
  1 <= n <= 1000
  思路：
  先定义sum[i]
  sum[i] = 0, if(i == 1)
  sum[i] = sum[i-1] + phi[i], if(i >= 2)
  ans = sum[n] * 2 + 3
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int pri[N],pcnt;
int phi[N];
void getphi(){
	phi[1]=1;
	for(int i=2;i<N;++i){
		if(!phi[i]){ pri[pcnt++]=i; phi[i]=i-1; }
		for(int j=0;i*pri[j]<N && j<pcnt;++j){
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			else phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
}
int sum[N];
int main(){
	int n;
	getphi();
	sum[2]=phi[2];
	for(int i=3;i<N;++i)
		sum[i]=sum[i-1]+phi[i];
	int T,cas=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d %d ",++cas,n);
		printf("%d\n",sum[n]*2+3);
	}
	return 0;
}
