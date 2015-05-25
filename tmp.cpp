#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	cout<<"'_' | ";
	for(int i=0;i<26;++i){
		cout<<"'"<<(char)(i+'a')<<"'"<<" | '"<<(char)(i+'A')<<"' | ";
	}
	
	for(int i=0;i<10;++i){
		cout<<"'"<<(char)(i+'0')<<"' | ";
	}

	cout<<"'_'A | ";
	for(int i=0;i<26;++i){
		cout<<"'"<<(char)(i+'a')<<"'A | "<<"'"<<(char)(i+'A')<<"'A | ";
	}
	for(int i=0;i<10;++i){
		cout<<"'"<<(char)(i+'0')<<"'A | ";
	}

	cout<<endl;
}
