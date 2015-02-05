#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	long long a,b,c,ans1,ans2;
	cin>>n;
	for(int i=1;i<=n;++i){
	cin>>a>>b>>c;
	ans1=(a-1)+(b-1)*a+(c-1)*a*b;
	ans2=ceil(log(a)/log(2))+ceil(log(b)/log(2))+ceil(log(c)/log(2));
	cout<<"Case #"<<i<<": "<<ans1<<' '<<ans2<<endl;
	}
	return 0;
}
