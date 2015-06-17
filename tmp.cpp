#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<string>
using namespace std;
map< string,map<string,vector<string> > > mp;
int main(){
	vector<string> v;
	v.push_back("A");
	mp["A"]["a"]=v;
	cout<<mp["A"]["a"].size()<<endl;
}
