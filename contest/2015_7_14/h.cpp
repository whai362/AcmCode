#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
#define LL long long
const int MOD=1000000007;
const int JZ=301;
const int N=10000005;
struct Value{
	int l,r;
	Value(){}
	Value(int _l,int _r){
		l=_l;
		r=_r;
	}
};
//LL get_hash(string str){
//	LL ret=0;
//	for(int i=0;i<str.size();++i){
//		ret=(ret*JZ%MOD+str[i])%MOD;
//	}
//	return ret;
//}
map<string,Value> mp;
string header;
int jiexi(int begin,char text[]){
	int i=begin+1;
	while(text[i]!='}'){
		if(text[i]=='"'){
			string key="";
			Value value;
			int p=i;
			while(text[p]!=':'){
				key+=text[p];
				++p;
			}
			++p;
			if(text[p]=='{'){
				value.l=p;
				header=header+key+".";
				
				value.r=jiexi(p,text);

				int header_end=header.length();
				header.erase(header.end()-1);
				--header_end;
				while(header_end && header[header_end-1]!='.'){
					header.erase(header.end()-1);
					--header_end;
				}
			}
			else{
				value.l=p;
				int q=p+1;
				while(text[q]!='"') ++q;
				value.r=q;
			}
			//cout<<header+key<<' '<<value.l<<' '<<value.r<<endl;
			if(header.size() + key.size() <30)
				mp[header+key]=value;
			i=value.r;
		}
		++i;
	}
	
	return i;
}
//char q[N];
void gao(char text[]){
	header="";
	jiexi(0,text);
	int m;
	//cin>>m;
	scanf("%d",&m);
	string q;
	for(int i=0;i<m;++i){
		cin>>q;
		//scanf("%s",q);
		//int hash_value=get_hash(q);
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
	mp.clear();
}
char text[N];
int main(){
	//ios::sync_with_stdio(false);
	int T;
	//cin>>T;
	scanf("%d",&T);
	while(T--){
		init();
		//cin>>text;
		scanf("%s",text);
		gao(text);
	}
	return 0;
}
