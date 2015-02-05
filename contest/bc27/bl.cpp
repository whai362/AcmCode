#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	cout<<1<<endl;
	cout<<100<<' '<<1<<endl;
	for(int i=0;i<99;++i){
		cout<<1000000000-1;
		if(i!=98) cout<<' ';
		else cout<<endl;
	}
	cout<<1<<' '<<100<<endl;
}
