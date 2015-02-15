#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[105];
int main(){
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;++i){
		if(i==0 && 9-str[i]+'0'==0) continue;
		if(str[i]-'0'>9-(str[i]-'0')) str[i]=9-str[i]+2*'0';
	}
	int i;
	int flag=0;
	for(i=0;i<len;++i){
		if(str[i]>'0'){ putchar(str[i]); flag=1; break; }
	}
	++i;
	for(;i<len;++i){ flag=1; putchar(str[i]); }
	//if(flag==0) putchar('0');
	puts("");
	return 0;
}
