#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int tab[300];
const int N=2*1e5+10;
char s[N],t[N];
int main(){
	scanf("%s%s",s,t);
	int len=strlen(t);
	for(int i=0;i<len;++i){
		++tab[t[i]];
	}
	int ansa=0,ansb=0;
	len=strlen(s);
	for(int i=0;i<len;++i){
		if(tab[s[i]]>0){ --tab[s[i]]; ++ansa; s[i]=0;}
		//else{
		//	if(s[i]>='a' && s[i]<='z') s[i]=s[i]-'a'+'A';
		//	else s[i]=s[i]-'A'+'a';
		//	if(tab[s[i]]>0){ --tab[s[i]]; ++ansb; }
		//}
	}
	for(int i=0;i<len;++i){
		if(s[i]){
			if(s[i]>='a' && s[i]<='z') s[i]=s[i]-'a'+'A';
			else s[i]=s[i]-'A'+'a';
			if(tab[s[i]]>0){ --tab[s[i]]; ++ansb;}
		}
	}
	cout<<ansa<<' '<<ansb<<endl;
	return 0;
}
