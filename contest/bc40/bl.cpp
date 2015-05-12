#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int gao(string s){
	int ret=0;
	for(int i=0;i<s.length();++i){
		for(int j=0;j<i;++j){
			if(s[j]>s[i]) ++ret;
		}
	}
	return ret;
}
int main(){
	string str="1234";
	int ans=0;
	ans+=gao(str);
	cout<<str<<endl;
	while(next_permutation(str.begin(),str.end())){
		cout<<str<<endl;
		if(str=="4321") break;
		ans+=gao(str);
		cout<<ans<<endl;
		//cout<<str<<endl;
	}
	//cout<<endl;
	cout<<ans<<endl;
	return 0;
}
