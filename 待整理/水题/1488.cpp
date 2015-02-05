#include<iostream>
#include<string>
using namespace std;
int main(){
	int flag=1;
	string str;
	while(getline(cin,str)){
		for(int i=0;i<str.size();++i){
			if(str[i]=='"'&&flag==1) cout<<"``",flag=0;
			else if(str[i]=='"'&&flag==0) cout<<"''",flag=1;
			else cout<<str[i];
		}
		cout<<endl;
	}
	return 0;
}
