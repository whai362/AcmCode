#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b;
	int n;
	cin>>n;
	cin>>a;
	int ans=a;
	cout<<a<<endl;
	for(int i=1;i<n;++i){
		cin>>a;
		ans=__gcd(ans,a);
		cout<<ans<<endl;
	}
	//cin>>a>>b;
	//if(a<b) swap(a,b);
	//for(int i=1;i<10;++i){
	//	for(int j=1;j<10;++j){
	//		cout<<i<<' '<<j<<' '<<i*a-j*b<<endl;
	//	}
	//}
	return 0;
}
