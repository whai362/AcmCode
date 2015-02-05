#include<cstdio>
#include<iostream>
using namespace std;
int m[1005][1005];
long long a[1005];
char str[1005];
const long long MOD=1e9+7;
int n;
long long gao(int num,int c,int r){
	//long long tmp=(num*(a[n-1-c]+a[n-1-r]))%MOD;
	//tmp=(tmp*(c+1+r+1))%MOD;
	long long tmp1=(num*a[n-1-r])%MOD;
	tmp1=(tmp1*(r+1))%MOD;
	long long tmp2=(num*a[n-1-c])%MOD;
	tmp2=(tmp2*(c+1))%MOD;
	return (tmp1+tmp2)%MOD;
}
int main(){
	a[0]=1;
	for(int i=1;i<1005;++i){
		a[i]=a[i-1]*10%MOD;
	}
	long long tmp=0;
	for(int i=0;i<1005;++i){
		tmp+=a[i];
		tmp%=MOD;
		a[i]=tmp;
	}
	scanf("%d",&n);
	long long ans=0;
	for(int i=0;i<n;++i){
		scanf("%s",str);
		for(int j=0;j<n;++j){
			m[i][j]=str[j]-'0';
			ans=(ans+gao(m[i][j],i,j))%MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}
