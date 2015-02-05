#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b,n,f;
	cin>>a>>b>>n;
	while(1){
		n-=__gcd(a,n);
		if(!n){
			f=0;
			break;
		}
		//cout<<n<<endl;
		n-=__gcd(b,n);
		if(!n){
			f=1;
			break;
		}
		//cout<<n<<endl;
	}
	cout<<f<<endl;
	return 0;
}
