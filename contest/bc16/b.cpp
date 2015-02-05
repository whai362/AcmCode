#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005;
int duo[N],dp[N],a[N];
int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		memset(dp,0,sizeof(dp));
		memset(duo,0,sizeof(duo));
		for(int i=0;i<n;++i){
			dp[i]=1;
			int _max=0;
			for(int j=0;j<i;++j){
				if(a[j]<a[i] && dp[j]>_max){
					_max=dp[j];
				}
			}
			int flag=0,cnt=0;
			for(int j=0;j<i;++j){
				if(a[j]<a[i] && dp[j]==_max){
					if(duo[j]) flag=1;
					++cnt;
				}
			}
			if(flag || cnt>1) duo[i]=1;
			dp[i]=_max+1;
		}
		int _maxl=0;
		for(int i=0;i<n;++i){
			if(dp[i]>_maxl)
				_maxl=dp[i];
		}
		int ad=0,acnt=0;
		for(int i=0;i<n;++i){
			if(dp[i]==_maxl){
				if(duo[i]) ad=1;
				++acnt;
			}
		}
		if(ad || acnt>1) printf("%d\n",_maxl);
		else printf("%d\n",_maxl-1);
	}
	return 0;
}
