#include<iostream>
#include<string>
using namespace std;
int main(){
	cout<<1<<' '<<1<<endl;
	string str="";
	for(int i=0;i<3*1e5;++i){
		str=str+'a';
	}
	cout<<str<<endl;
	str[0]='b';
	cout<<str<<endl;
}
