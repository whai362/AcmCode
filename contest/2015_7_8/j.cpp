#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
LL a[5];
void gao(){
	LL ans;
	sort(a,a+3);
	if(a[0]==0 && a[1]==0 && a[2]==0) puts("0");
	else if(a[0]==0 && a[1]==0){
		LL tmp=a[2];
		if(tmp==1) puts("0");
		else if(tmp==2) puts("1");
		else{
			ans=1;
			tmp-=2;
			cout<<ans+tmp*2<<endl;
		}
	}
	else if(a[0]==0){
		LL tmp=a[1]+a[2];
		if(tmp<=5){
			ans=tmp*(tmp-1)/2;
			cout<<ans<<endl;
		}
		else{
			ans=10;
			tmp-=5;
			ans+=tmp*4;
			cout<<ans<<endl;
		}
	}
	else{
		LL tmp=a[0]+a[1]+a[2];
		if(tmp<=7){
			ans=tmp*(tmp-1)/2;
			cout<<ans<<endl;
		}
		else{
			ans=21;
			tmp-=7;
			ans+=tmp*6;
			cout<<ans<<endl;
		}
	}

}
int main(){
	while(cin>>a[0]>>a[1]>>a[2]){
		gao();
	}
	return 0;
}
