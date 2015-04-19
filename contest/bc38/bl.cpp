#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=a;i<=b;++i){
		int _min=100000000,ou;
		for(int j=c;j<=d;++j){
			if((i^j)<_min){
				_min=(i^j);
				ou=j;
			}
		}
		cout<<i<<' '<<ou<<' '<<(i^ou)<<endl;
	}
}
