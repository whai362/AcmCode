#include<cstdio>
#include<iostream>
using namespace std;
const int p=11;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		int sum=0;
		for(int j=1;j<p;++j){
			int res=1;
			for(int k=0;k<i;++k){
				res=(res*j)%p;
			}
			sum=(sum+res)%p;
		}
		cout<<sum<<' ';
	}
	cout<<endl;
	return 0;
}
