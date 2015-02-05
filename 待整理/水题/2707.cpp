#include<iostream>
using namespace std;
int main(){
	int a,b,c,d,t;
	while(cin>>a>>b>>c>>d&&(a||b||c||d)){
		if(a<b) t=a,a=b,b=t;
		if(c<d) t=c,c=d,d=t;
		a=c*100/a;
		b=d*100/b;
		if(a>100) a=100;
		if(b>100) b=100;
		if(a>b) cout<<b<<'%'<<endl;
		else cout<<a<<'%'<<endl;
	}
	return 0;
}
