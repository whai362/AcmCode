#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	int i,j,n;
	string tmp,s1,s2;
	cin>>n;
	s1="<3";
	for(i=0;i<n;++i){
		cin>>tmp;
		s1=s1+tmp+"<3";
	}
	cin>>s2;
	for(i=0,j=0;i<s1.size() && j<s2.size();){
		if(s1[i]==s2[j]) ++i,++j;
		else ++j;
	}
	if(i==s1.size()) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
