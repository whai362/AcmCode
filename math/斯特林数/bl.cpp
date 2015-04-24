#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	int sum=1;
	for(int i=1;i<=11;++i){
		sum*=i;
	}
	cout<<sum<<endl;
}
