#include<iostream>
using namespace std;
int main(){
	__int64 n,k,t;
	cin>>n>>k;
	t=(n+1)/2;
	if(k>t)
	  cout<<(k-t)*2<<endl;
	else
	  cout<<k*2-1<<endl;
	return 0;
}
