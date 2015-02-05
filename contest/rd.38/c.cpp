#include<iostream>
#include<algorithm>
using namespace std;
__int64 _max(__int64 a,__int64 b){
	if(a>b) return a;
	return b;
}
int main(){
	__int64 ans,n;
	cin>>n;
	if(n==1) cout<<1<<endl;
	else if(n==2) cout<<2<<endl;
	else{
		if(n%2)
		  ans=n*(n-1)*(n-2);
		else{
			ans=_max(n*(n-1)*(n-2)/2,n*(n-1)*(n-3)/__gcd(n,n-3));
			ans=_max(ans,(n-1)*(n-2)*(n-3));
			if(n==6) ans=60;
		}
		cout<<ans<<endl;
	}
	return 0;
}
