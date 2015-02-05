#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
__int64 h[N],dp[N],_max[N];
int main(){
	int n;
	int a,lim=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		h[a]+=(__int64)a;
		lim=max(a,lim);
	}
	_max[1]=dp[1]=h[1];
	dp[2]=h[2];
	_max[2]=max(dp[1],dp[2]);
	for(int i=3;i<=lim;++i){
		dp[i]=_max[i-2]+h[i];
		_max[i]=max(_max[i-1],dp[i]);
	}
	cout<<_max[lim]<<endl;
	return 0;
}
