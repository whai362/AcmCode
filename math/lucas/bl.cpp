#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int gao(int x,int n,int m){
	int flag=0;
	int cnt=0;
	for(int i=0;i<n;++i){
		if((1<<i) & x){
			++cnt;
			if(i && ((1<<(i-1)) & x)) flag=1;
		}
	}
	if(cnt==m)
	   return !flag;
	else return 0;
}
int main(){
	int n,m;
	for(n=1;n<=10;++n){
		for(m=0;m<=n;++m){
			int lim=(1<<n);
			int ans=0;
			for(int i=0;i<lim;++i){
				ans+=gao(i,n,m);
			}
			cout<<ans<<'	';
		}
		cout<<endl;
	}
}
