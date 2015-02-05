#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
#define LL __int64
int main(){
	LL h,n;
	cin>>h>>n;
	LL l=1,r=((1LL)<<h),mid;
	//cout<<l<<' '<<r<<endl;
	int flag=1;
	LL ans=1;
	LL add=(1LL)<<h;
	while(l<r){
		mid=(l+r)>>1;
		if(flag){
			if(n>mid){
				ans+=add;
				l=mid+1;
			}
			else{
				ans+=1;
				r=mid;
				flag=!flag;
			}
		}
		else{
			if(n<=mid){
				ans+=add;
				r=mid;
			}
			else{
				ans+=1;
				l=mid+1;
				flag=!flag;
			}
		}
		//cout<<l<<' '<<r<<' '<<mid<<' '<<ans<<endl;
		add>>=1;
	}
	cout<<ans-1<<endl;
	return 0;
}
