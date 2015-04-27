#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	srand(1234);
	int n=100;
	cout<<n<<endl;
	for(int i=0;i<n;++i){
		cout<<rand()%100000<<' ';
	}
	cout<<endl;
}
