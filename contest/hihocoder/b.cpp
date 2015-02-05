#include<cstdio>
#include<iostream>
using namespace std;
#define M 1000000007
int main(){
	int cas=0,t;
	long long n,t1,t2,t3;
	cin>>t;
	while(t--){
	cin>>n;
	n=n%M;
	t1=((((1+n)%M)*n)%M)/2;
	t2=(((n*((n+1)%M))%M)*((2*n)%M+1))%M
	cout<<"Case "<<++cas<<": "<<t1<<endl;
	}
	return 0;
}

