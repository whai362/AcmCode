#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int len;
bool isVowel(char c){
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 1;
	return 0;
}
bool rule1(char str[]){
	int i;
	for(i=0;i<len;++i) if(isVowel(str[i])) return 1;
	return 0;
}
bool rule2(char str[]){
	int i;
	for(i=0;i<len-2;++i){
		if(isVowel(str[i])&&isVowel(str[i+1])&&isVowel(str[i+2])) return 0;
		else if(!(isVowel(str[i])||isVowel(str[i+1])||isVowel(str[i+2]))) return 0;
	}
	return 1;
}
bool rule3(char str[]){
	int i;
	for(i=0;i<len-1;++i) if(str[i]!='e'&&str[i]!='o'&&str[i]==str[i+1]) return 0;
	return 1;
}
int main(){
	char str[50];
	while(scanf("%s",str)&&(strlen(str)!=3||str[0]!='e'||str[1]!='n'||str[2]!='d')){
		len=strlen(str);
		if(rule1(str)&&rule2(str)&&rule3(str)) printf("<%s> is acceptable.\n",str);
		else printf("<%s> is not acceptable.\n",str);
	}
	return 0;
}
