#include<iostream>
using namespace std;
int main(){
	int i,n,x,t,s=0;
	cin>>n>>x;
	for(i=0;i<n;++i){
		cin>>t;
		s+=t;
	}
	if(s<0) s=-s;
	if(s>0){
		t=s/x;
		if(s%x) cout<<t+1<<endl;
		else cout<<t<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
