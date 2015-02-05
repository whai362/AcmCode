#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
	int i,j,max=0,f[30]={0};
	char str[100];
	while(cin.getline(str,sizeof(str))){
		for(i=0;i<strlen(str);++i){
			if(str[i]>='A'&&str[i]<='Z'){
				++f[str[i]-'A'];
				if(f[str[i]-'A']>max) max=f[str[i]-'A'];
			}
		}
	}
	for(i=max;i>=1;--i){
		for(j=0;j<26;++j){
			if(f[j]==i) --f[j],printf("*");
			else printf(" ");
			if(j!=25) printf(" ");
			else printf("\n");
		}
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
	return 0;
}
