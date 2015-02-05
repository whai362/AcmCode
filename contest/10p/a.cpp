#include<iostream>
using namespace std;
int main(){
	double a,b,t1,t2;
	a=b=0;
	while(cin>>t1>>t2){
		a+=t1*t2;
		b+=t2;
	}
	cout<<a/b<<endl;
	return 0;
}
