#include<iostream>
#include<algorithm>
using namespace std;
bool ok(string a){
	for(int i=0;i<a.length()-1;++i){
		if(a[i]>a[i+1]) return false;
	}
	return true;
}
int gao(string a){
	int ret=0;
	while(!ok(a)){
		for(int i=0;i<a.length()-1;++i)
			if(a[i]>a[i+1]) swap(a[i],a[i+1]);
		++ret;
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
		if(cnt==2) cout<<a<<endl;
	}
	for(int i=0;i<10;++i)
		cout<<o[i]<<' ';
	cout<<endl;
}
