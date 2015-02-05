#include<iostream>
#include<cstdio>
using namespace std;
int gao(int n,int k){
	int s=0;
	while(n){
		s=(s+n%k)%k;
		n/=k;
	}
	return s;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cout<<gao(i,k)<<' ';
	}
	cout<<endl;
	return 0;
}
