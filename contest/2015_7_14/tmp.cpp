/*
ID: icerupt1
PROG: lgame
LANG: C++11
*/

/* solution
 *
 *
*/

#include <fstream>
#include <iostream>
#include <string>
#include <tr1/unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::tr1;
#define PB push_back
ifstream dict_in("lgame.dict" );
ifstream 	  fin("lgame.in" );
ofstream 	 fout("lgame.out");

unordered_map<string, int> dic_pool,vis;

int _max;
vector<string> ans;
string letter="qwertyuiopasdfghjklzxcvbnm";
string number="76122541352146557637746525";

int button[30];

void deal(string str){
	string A="",B="";
	int i=0;
	while(str[i]!=';'){
		A+=str[i];
		++i;
	}
	++i;
	while(str[i]!=';'){
		B+=str[i];
		++i;
	}
	if(A>B) swap(A,B);
	if(A=="" && B=="") return ;
	if(A=="") str=B;
	else str=A+" "+B;
	
	if(vis[str]==1 || !(dic_pool[A]==1 && dic_pool[B]==1)) return ;
	vis[str]=1;
	int tmp=0;
	for(int i=0;i<str.length();++i){
		if(str[i]==' ') continue;
		tmp+=button[str[i]-'a'];
	}
	if(tmp==_max){
		ans.PB(str);
	}
	else if(tmp>_max){
		_max=tmp;
		ans.clear();
		ans.PB(str);
	}
}
void init(){
	for(int i=0;i<letter.size();++i){
		button[letter[i]-'a']=number[i]-'0';
	}
}
int main(){
	init();
	string str;
	string dic;
	fin>>str;
	str+=";;";
	dic_pool[""]=1;
	while(dict_in>>dic){
		if(dic==".") break;
		dic_pool[dic]=1;
	}
	sort(str.begin(),str.end());
	_max=0;
	deal(str);
	while(next_permutation(str.begin(),str.end())){
		deal(str);
	}
	fout<<_max<<endl;
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();++i){
		fout<<ans[i]<<endl;
	}
	return 0;
}

