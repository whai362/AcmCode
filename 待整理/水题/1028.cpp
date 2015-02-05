#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	string imf,web,cur="http://www.acm.org/";
	stack<string> f;
	stack<string> b;
	while(cin>>imf&&imf!="QUIT"){
		if(imf=="VISIT"){
			b.push(cur);
			while(!f.empty()) f.pop();
			cin>>web;
			cur=web;
			cout<<cur<<endl;
		}
		else if(imf=="BACK"){
			if(b.empty()) cout<<"Ignored"<<endl;
			else{
				f.push(cur);
				cur=b.top();
				b.pop();
				cout<<cur<<endl;
			}
		}
		else if(imf=="FORWARD"){
			if(f.empty()) cout<<"Ignored"<<endl;
			else{
				b.push(cur);
				cur=f.top();
				f.pop();
				cout<<cur<<endl;
			}
		}
	}
	return 0;	 
}
