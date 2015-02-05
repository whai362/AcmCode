#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n,s;
	int i;
	int a,sum=0,_max=0;
	cin>>n>>s;
	for(i=0;i<n;++i){
		cin>>a;
		sum+=a;
		if(a>_max) _max=a;
	}
	if(sum-_max>s) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}
