#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){

	srand(12345);
	int n=888;
	int m=8;
	cout<<n<<' '<<m<<endl;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout<<rand()%n<<' ';
		}
		cout<<endl;
	}
	cout<<n<<' '<<m<<endl;
	for(int i=0;i<n-2;++i){
		for(int j=0;j<m;++j){
			if((i+j)%5==0) cout<<'0'<<' ';
			else cout<<rand()%n<<' ';
		}
		cout<<endl;
	}
}
