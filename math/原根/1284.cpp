/*poj 1284
  题意：
  给出一个数n,求原根数目。
  限制：
  3 <= n < 65536; n为奇素数。
  思路：
  因为n是素数，所以模n的原根数=phi(phi(n))=phi(n-1)。
  phi(i) 可以预处理出来。
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int pri[N],pcnt;
int phi[N];
void getphi(){
	phi[1]=1;
	for(int i=2;i<N;++i){
		if(!phi[i]){ pri[pcnt++]=i; phi[i]=i-1; }
		for(int j=0;pri[j]*i<N && j<pcnt;++j){
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			else phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
}
int main(){
	int n;
	getphi();
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",phi[n-1]);
	return 0;
}
