#include<iostream>
using namespace std;
const int mod=2333333;
int a[mod+1];
int main(){
	int o=1;
	int i;
	for(i=0;i<100000;++i){
		cout<<o<<' ';
		o=o*2%mod;
		if(a[o]==1) break;
		a[o]=1;
	}
	cout<<endl;
	cout<<i<<endl;
}
