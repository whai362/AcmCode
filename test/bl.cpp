#include<iostream>
#include<algorithm>
using namespace std;
int gao(string a){
	int ret=0;
	for(int i=0;i<a.length();++i){
		for(int j=i+1;j<a.length();++j){
			if(a[i]>a[j]) ret++;
		}
	}
	return ret;
}
int o[20];
int main(){
	string a="1234";
	o[0]=1;
	while(next_permutation(a.begin(),a.end())){
		int cnt=gao(a);
		++o[cnt];
	}
	for(int i=0;i<10;++i)
		cout<<o[i]<<' ';
	cout<<endl;
}
