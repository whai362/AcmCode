#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
const double eps=1e-6;
long long n;
double dp[2000000];
map<long long,int> h;
bool eq(double a,double b){
	if(fabs(a-b)<eps)
		return true;
	return false;
}
void gao(int op){
	int len=(int)(log(op)/log(2.0))+1;
	if(op & 1){
		dp[op]=dp[op>>1]/len;
	}
	else{
		dp[op]=dp[op>>1]*len;
	}
	long long tmp=(long long)(dp[op]+eps);
	if(eq(dp[op],double(tmp))){
		if(h.find(tmp)==h.end()){
			h.insert(make_pair(tmp,len));
		}
	}
}
int main(){
	int lim=1<<20,T;
	dp[1]=1.0;
	for(int i=2;i<lim;++i){
		gao(i);
	}
	/*for(int i=1;i<100;++i){
		cout<<i<<' '<<(int)(log(i)/log(2.0))+1<<' '<<dp[i]<<endl;
	}*/
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		if(h.find(n)!=h.end()){
			printf("%d\n",h[n]);
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
