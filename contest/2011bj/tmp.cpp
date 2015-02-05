#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int ans=0;
	int n=2000000;
	for(int i=1;i<=1000000;++i){
		ans+=n/i;
	}
	cout<<ans<<endl;
	return 0;
}
