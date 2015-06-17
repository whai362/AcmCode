#include<iostream>
#include<cstdio>
#include<ctime>
#include<string>
using namespace std;
#define LL __int64
const int MOD=9901;
int main(){
	int n,m;
	cin>>n>>m;
	int t=1;
	for(int i=0;i<m;++i){
		t*=n;
	}
	int ans=0;
	for(int i=1;i<=t;++i){
		if(t%i==0){
			ans+=i;
		}
	}
	cout<<ans%9901<<endl;
}
