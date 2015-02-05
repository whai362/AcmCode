#include<iostream>
using namespace std;
int main(){
	int n,d,u;
	while(cin>>n>>u>>d && (n || u || d)){
	int len=u,t=1;
	while(len<n){
		len-=d;
		++t;
		len+=u;
		++t;
	}
	cout<<t<<endl;
	}
	return 0;
}
