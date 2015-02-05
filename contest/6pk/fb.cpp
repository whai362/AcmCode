#include<iostream>
#include<cstdio>
using namespace std;
long long f[1000];
int main(){
	f[0]=1,f[1]=1,f[2]=2,f[3]=5;
	int i,j;
	for(i=4;i<21;++i){
		long long ans=0;
		for(j=0;j<i;++j){
			ans+=2*f[j];
		}
		//cout<<ans<<endl;
		ans-=f[i-1]+f[i-2];
		f[i]=ans;
		cout<<ans<<' ';
	}
	cout<<endl;
	return 0;
}
