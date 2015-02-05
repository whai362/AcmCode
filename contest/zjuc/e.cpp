#include<iostream>
using namespace std;
int main(){
	long long a,i,n,t;
	while(cin>>n){

		a=n*n*(n-1)-(n-1)*(n-2)+(n*n-2*(n-2))/2;
		cout<<a<<endl;
	}
	return 0;
}

