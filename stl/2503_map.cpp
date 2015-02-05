#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
map<string,string> _map;
int main(){
	ios_base::sync_with_stdio(false);
	string str,t1,t2;
	int len;
	while(getline(cin,str)){
		len=str.length();
		if(len>0){
			int it=str.find(' ');
			//cout<<it<<endl;
			t1=str.substr(0,it);
			t2=str.substr(it+1,len-(it+1));
			//cout<<t1<<endl;
			//cout<<t2<<endl;
			_map.insert(make_pair(t2,t1));
		}
		else break;
	}
	while(cin>>str){
		if(_map.find(str)!=_map.end())
			cout<<_map[str]<<endl;
		else
			cout<<"eh"<<endl;
	}
	return 0;
}
