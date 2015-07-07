/*
ID: icerupt1
PROG: stamps
LANG: C++11
*/
#include<iostream>
#include<fstream>
//#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
ifstream fin ("stamps.in" );
ofstream fout("stamps.out");
const int INF=0x3f3f3f3f;
int a[55];
int dp[2000005];
int main(){
	int k,n;
	//scanf("%d%d",&k,&n);
	fin>>k>>n;
	for(int i=0;i<n;++i){
		//scanf("%d",&a[i]);
		fin>>a[i];
	}
	sort(a,a+n);
	memset(dp,0x3f,sizeof(dp));
	int MAX=a[n-1]*k;
	dp[0]=0;
	for(int i=0;i<n;++i){
		for(int j=a[i];j<=MAX;++j){
			dp[j]=min(dp[j-a[i]]+1,dp[j]);
		}
	}
	int ans=1;
	while(dp[ans]<=k){
		++ans;
	}
	//cout<<ans-1<<endl;
	fout<<ans-1<<endl;
	return 0;
}
