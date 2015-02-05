#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[25];
int main(){
	scanf("%s",str);
	int len=strlen(str);
	int ans=0;
	int cnt=1;
	for(int i=0;i<len-1;++i){
		if(str[i]=='-') continue;
		ans+=(str[i]-'0')*cnt;
		++cnt;
	}
	int ch;
	if(str[len-1]=='X')
		ch=10;
	else
		ch=str[len-1]-'0';
	char out;
	if(ans%11==10)
		out='X';
	else
		out=ans%11+'0';
	if(ans%11==ch)
		printf("Right");
	else{
		str[len-1]=out;
		printf(str);
	}
	return 0;
}
