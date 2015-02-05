#include<iostream>
using namespace std;
int main(){
	int i,n,p,k;
	cin>>n>>p>>k;
	if(p>=1 && p<=n){
	if(p-k>1) cout<<"<< ";
	for(i=(p-k<1?1:p-k);i<p;++i){
		cout<<i<<' ';
	}
	cout<<'('<<p<<')'<<' ';
	for(i=p+1;i<=p+k && i<=n;++i){
		cout<<i<<' ';
	}
	if(p+k<n) cout<<">>"<<endl;
	}
	return 0;
}
