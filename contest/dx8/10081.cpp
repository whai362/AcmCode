#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	cout<<__gcd(a,b)<<endl;
	cout<<a*b/__gcd(a,b)<<endl;
	return 0;
}
