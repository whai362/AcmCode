/*hdu 5167 Fibonacci
  题意：
  fi[0]=0,fi[1]=1
  fi[i]=fi[i-1]+fi[i-2] i>1
  给出一个数n,问这个数能不能有fi[]相乘得来。
  限制：
  0 <= n <= 1e9
  思路：
  1e9以内的斐波那契数只有44个，用记忆化搜索可以解决这道题。
 */
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define LL __int64
const int LIM=1e9+5;
LL fi[300];
map<int,int> vis;
int cnt=0;
void predo(){
	fi[1]=1;
	fi[2]=1;
	vis[0]=1;
	vis[1]=1;
	cnt=2;
	for(int i=3;fi[i-1]+fi[i-2]<LIM;++i){
		fi[i]=fi[i-1]+fi[i-2];
		vis[fi[i]]=1;
		++cnt;
	}
}
bool gao(int n){
	if(vis[n]==1) return true;
	if(vis[n]==-1) return false;
	for(int i=3;i<=cnt;++i){
		if(fi[i]>n) break;
		if(n%fi[i]==0){
			if(gao(n/fi[i])){
				vis[n]=1;
				return true;
			}
			else{
				vis[n]=-1;
			}
		}
	}
	return false;
}
int main(){
	predo();
	int T;
	scanf("%d",&T);
	LL n;
	while(T--){
		scanf("%I64d",&n);
		if(gao(n)) puts("Yes");
		else puts("No");
	}
	return 0;
}
