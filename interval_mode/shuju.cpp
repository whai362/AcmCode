#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n=10000,q=5000;
	cout<<n<<' '<<q<<endl;
	for(int i=0;i<n;++i){
		cout<<(i%1000*1231)%1000000007+700000000<<' ';
	}
	cout<<endl;
	for(int i=0;i<q;++i){
		cout<<i+1<<' '<<n-i<<endl;
	}
	return 0;
}
