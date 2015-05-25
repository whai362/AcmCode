#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int tab[100];
string trans(string str){
	char s[100];
	string ret="";
	for(int i=0;i<str.length();++i){
		s[tab[i]]=str[i];
	}
	for(int i=0;i<str.length();++i){
		ret+=s[i];
	}
	return ret;
}
bool ok(string str){
	string pre,end;
	for(int i=0;i<str.length();++i){
		tab[str[i]-'0']=i;
	}
	for(int i=0;i<3;++i){
		str=trans(str);
		if(i==0) pre=str;
	}
	return pre==str;
}
int main(){
	string str="0123456789";
	int ans=1;
	while(next_permutation(str.begin(),str.end())){
		if(ok(str)) ++ans;
	}
	cout<<ans<<endl;
}

