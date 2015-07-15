#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<cstring>
#include<map>
using namespace std;
const int N=10000005;
struct Value{
	int l,r;
	Value(){}
	Value(int _l,int _r){
		l=_l;
		r=_r;
	}
};
map<string,Value> mp;
string header;
stack<Value> s;
int jiexi(char text[]){
	int len=strlen(text);
	string key="";
	Value value;
	for(int i=0;i<len;++i){
		
		if(text[i]=='{'){
			if(key.size()){
				header=header+key+'.';
				//cout<<"header: "<<key<<' '<<header<<endl;
				key="";
			}
			value.l=i;
			value.r=-1;
			s.push(value);
		}
		else if(text[i]=='}'){
			Value now=s.top();
			s.pop();
			now.r=i;
			if(header.size()){
				int header_end=header.length();
				header.erase(header.end()-1);
				if(header.size()<30)
					mp[header]=now;
				key="";
				--header_end;
				while(header_end && header[header_end-1]!='.'){
					header.erase(header.end()-1);
					--header_end;
				}
			}
		}
		else if(text[i]=='"'){
			int p=i;
			while(text[p]!=':'){
				key+=text[p];
				++p;
			}
			++p;
			if(text[p]=='"'){
				value.l=p;
				int q=p+1;
				while(text[q]!='"') ++q;
				value.r=q;
				//cout<<"header.key: "<<header+key<<endl;
				if(header.size()+key.size()<30)
					mp[header+key]=value;
				key="";
				i=value.r;
			}
			else{
				i=p-1;
			}
			//cout<<"key: "<<i<<' '<<key<<endl;
		}
	}
}
void gao(char text[]){
	jiexi(text);
	int m;
	cin>>m;
	string q;
	for(int i=0;i<m;++i){
		cin>>q;
		if(mp.find(q)==mp.end()){
			puts("Error!");
			continue;
		}
		Value value=mp[q];
		char tmp=text[value.r+1];
		text[value.r+1]=0;
		puts(text+value.l);
		text[value.r+1]=tmp;
	}
}
void init(){
	header="";
	mp.clear();
}
char text[N];
int main(){
	int T;
	cin>>T;
	while(T--){
		init();
		cin>>text;
		gao(text);
	}
	return 0;
}
