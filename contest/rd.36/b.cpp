#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-10
int prime[1000005];
bool is_prime(int n){
	if(prime[n]==1) return true;
	if(prime[n]==-1) return false;
	if(n==1) return false;
	if(n==2||n==3) return true;
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			prime[n]=-1;
			return false;
		}
	}
	prime[n]=1;
	return true;
}
int main(){
	int i,n,tmp;
	double x;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>x;
		tmp=(int)sqrt(x);
		if(fabs(double(tmp)*double(tmp)-x)>eps)
		    cout<<"NO"<<endl;
		else{
			if(is_prime(tmp)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
