#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	const int L=1000;
	int c=300000/L;
	cout<<c<<' '<<c<<endl;
	string str="";
	for(int i=0;i<L-9;++i)
		str=str+'a';
	string nx="aaabbbccc";
	for(int i=0;i<c;++i){
		cout<<str+nx<<endl;
		next_permutation(nx.begin(),nx.end());
	}
	for(int i=0;i<9;++i)
		str=str+'a';
	for(int i=0;i<c;++i){
		cout<<str<<endl;
	}
}
