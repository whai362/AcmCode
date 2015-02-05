#include<cstdio>
#include<iostream>
using namespace std;
long long c(int n,int k){
	long long i,tmp=1;
	for(i=0;i<k;++i){
		tmp*=(n-i);
	}
	for(i=1;i<=k;++i){
		tmp/=i;
	}
	return tmp;
}
int main(){
	long long n;
	while(cin>>n){
		if(n<3) cout<<0<<endl;
		else if(n==3) cout<<1<<endl;
		else if(n==4) cout<<8<<endl;
		else
			cout<<c(n*(n-3)/2,3)+2*n*(n-3)+n<<endl;
	}
	return 0;
}
