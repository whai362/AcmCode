#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
int main(){
	LL o=1;
	for(int i=2;i<=18;++i){
		o*=i;
		cout<<o<<endl;
	}
	cout<<o<<endl;
	return 0;
}
