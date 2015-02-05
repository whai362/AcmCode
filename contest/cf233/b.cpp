#include<iostream>
using namespace std;
__int64 pow(int n){
	int i;
	__int64 ans=1;
	for(i=0;i<n;++i){
		ans*=2;
	}
	return ans;
}
int main(){
	int i,n;
	__int64 ans=0;
	char str[100];
	cin>>n>>str;
	for(i=0;i<n;++i){
		if(str[i]=='B') ans+=pow(i);
	}
	cout<<ans<<endl;
	return 0;
}
