#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
LL a[5];
LL b[5];
void gao(){
	LL ans;
	sort(a,a+3);
	LL tmp=0;
	for(int i=0;i<3;++i){
		b[i]=min((LL)2,a[i]);
		tmp+=b[i];
	}
	ans=tmp*(tmp-1)/2;
	for(int i=0;i<3;++i){
		ans+=(a[i]-b[i])*tmp;
	}
	cout<<ans<<endl;
}
int main(){
	while(cin>>a[0]>>a[1]>>a[2]){
		gao();
	}
	return 0;
}
