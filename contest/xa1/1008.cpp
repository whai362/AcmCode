#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a[6];
int gao(string str){
	int ans=0;
	for(int i=0;i<7;++i){
		ans+=(str[i]-'0')^a[i];
	}
	return ans;
}
int main(){
	string str="123456";
	cout<<'\"'<<str<<"\",";
	while(next_permutation(str.begin(), str.end())){
		cout<<'\"'<<str<<"\",";
	}
	
}
