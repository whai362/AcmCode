#include<iostream>
#include<cstdio>
using namespace std;
string text;
string key;
void gao(){
	string tmp="";
	int st=key.length()-1;
	while(st>=0 && key[st]!='.'){
		--st;
	}
	for(int i=st+1;i<key.length();++i){
		tmp+=key[i];
	}
	//cout<<tmp<<endl;
	int index=text.find(tmp);
	if(index==-1) cout<<"Error!"<<endl;
	else{
		index=index+tmp.length()+1;
		char end;
		if(text[index]=='"'){
			cout<<'"';
			end='"';
		}
		else{
			cout<<'{';
			end='}';
		}
		++index;
		while(text[index]!=end){
			cout<<text[index++];
		}
		cout<<end<<endl;

	}
}
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		cin>>text;
		int m;
		cin>>m;
		while(m--){
			cin>>key;
			gao();
		}
	}
	return 0;
}
