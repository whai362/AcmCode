#include<iostream>
#include<cstdio>
using namespace std;
#define MOD 1000000007
long long kind[105];
int main(){
	int cas=0,n,t;
	int i;
	long long a,ans,tmp;
	kind[1]=0;
	kind[2]=1;
	kind[3]=2;
	tmp=1;
	for(i=4;i<=100;++i){	//ѧϰ
		kind[i]=((i-1)*((kind[i-1]+kind[i-2])%MOD))%MOD;
	}
	scanf("%d",&t);
	while(t--){
	scanf("%d",&n);
	ans=1;
	for(i=0;i<n;++i){
		cin>>a;
		ans=(ans*a)%MOD;
	}
	cout<<"Case "<<++cas<<": "<<(ans*kind[n])%MOD<<endl;
	}
	return 0;
}
