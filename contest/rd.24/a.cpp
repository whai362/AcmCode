#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int flag=0,i,len;
	char s[300];
	cin>>s;
	len=strlen(s);
	for(i=0;i<len;++i){
		if(s[i]!='W' || s[i+1]!='U' || s[i+2]!='B'){
			if(flag==2) cout<<' ';
			cout<<s[i];
			flag=1;
		}
		else{
			i=i+2;
			if(flag==1) flag=2;
		}
	}
	return 0;
}
