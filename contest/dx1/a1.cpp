#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	__int64 n,p,tmp;
	while(cin>>n>>p){
	tmp=p-1;
	tmp=n/tmp;
	if(tmp%2==0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
	}
	return 0;
}
