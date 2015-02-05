#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	int i,t,l;
	string _in,_out;
	cin>>t;
	getchar();
	while(t--){
		getline(cin,_in);
		l=_in.size();
		_out="";
		for(i=0;i<l;++i){
			if(_in[i]=='_') _out+=_in;
			else if(_in[i]=='!') _out+="Hello, world!";
		}
		//cout<<_out<<endl;
		if(_in==_out) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
