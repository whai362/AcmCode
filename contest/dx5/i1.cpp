#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<100;++i){
		cout<<i<<' '<<(n^(i-n))<<' '<<(n^i)<<endl;
	}
	cout<<endl;
}
