#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s,t;
int main(){
	cin>>s>>t;
	int flag=0;
	for(int i=s.length()-1;i>=0;--i){
		if(s[i]=='z') s[i]='a';
		else{ ++s[i]; flag=1; break; }
	}
	if(s>=t) flag=0;
	if(flag) cout<<s<<endl;
	else puts("No such string");
	return 0;
}
