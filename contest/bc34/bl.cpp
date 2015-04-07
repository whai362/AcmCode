#include<iostream>
using namespace std;
int main(){
	int n,m;
	n=m=20000;
	cout<<n<<' '<<m<<endl;
	for(int i=n;i>0;--i){
		cout<<i<<' ';
	}
	cout<<endl;

	for(int i=0;i<m;++i){
		cout<<0<<' '<<n<<' '<<n+1<<endl;
		++n;
	}
}
