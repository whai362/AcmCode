#include<iostream>
#include<cstdio>
using namespace std;
int a[]={5,54,550,5700,58830,607752};
int main(){
	int T;
	int n;
	cin>>T;
	while(T--){
		cin>>n;
		cout<<a[n-1]<<endl;
	}
	return 0;
}
