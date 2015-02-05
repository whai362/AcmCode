#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
int main(){
	int T;
	string s,tmp;
	while(cin>>T && T){
	while(T--){
		cin>>s;
		int cnt=0,len=s.length();
		map<string,int> h;
		for(int i=0;i<len;++i){
			for(int j=0;j<=len;++j){
				h.insert(pair<string,int>(s.substr(i,j),cnt++));
			}
		}
		tmp="A";
		map<string,int>::iterator p;
		while(1){
			p=h.find(tmp);
			if(p==h.end()) break;
			else tmp+='A';
		}
		cout<<tmp<<endl;
	}
	}
	return 0;
}
