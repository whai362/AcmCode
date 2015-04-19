/*zoj 3778 Talented Chef
  题意：
  有n个饼，给出完成每个饼所需要的时间t1,t2,...,tn，现在有m个锅(也就是说可以同时煎m个饼)，问完成所有饼至少需要多少时间。
  限制：
  1 <= n,m,ti <= 40000
  思路：
  贪心
  ans=max(ceil(sigma(1~n,ti)/m),max(ti))
 */
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int a;
		int sum=0,_max=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			sum+=a;
			_max=max(_max,a);
		}
		int ans=max((sum+m-1)/m,_max);
		printf("%d\n",ans);
	}
	return 0;
}
