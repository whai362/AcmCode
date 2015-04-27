#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	cout<<1<<endl;
	cout<<52<<endl;
	string biao="23456789TJQKA";
	string t="1234";
	for(int i=0;i<biao.length();++i){
		for(int j=0;j<t.length();++j){
			cout<<biao[i]<<t[j]<<' ';
		}
		cout<<endl;
	}
}

