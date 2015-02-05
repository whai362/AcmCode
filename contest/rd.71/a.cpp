#include<iostream>
using namespace std;
int main(){
	double a,b,c,d,q,t1,t2;
	cin>>a>>b>>c>>d;
	t1=a/b;
	t2=c/d;
	q=(1-t1)*(1-t2);
	cout<<t1/(1-q)<<endl;
	return 0;
}
