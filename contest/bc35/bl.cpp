#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
int main(){
	double ans=1;
	for(int i=13;i<=24;++i)
		ans*=i;
	for(int i=1;i<=12;++i)
		ans/=i;
	cout<<ans<<endl;
}
